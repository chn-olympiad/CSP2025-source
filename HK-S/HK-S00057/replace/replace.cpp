#include <bits/stdc++.h>
using namespace std;
struct pencil{
    string s1;
    string s2;
    int siz;
};
vector <pencil> v;
bool cmp(pencil a, pencil b){
    return a.s1<b.s1;
}
int lb(string s, int l, int r){
    if(s>v[r].s1){
        return -1;
    }else if(s<v[l].s1){
        return 0;
    }
    while(l<r){
        int mid=(l+r)/2;
        if(v[mid].s1<s){
            l=mid+1;
        }else{
            r=mid;
        }
        //cout<<"*";
    }
    return l;
}
int ub(string s, int l, int r){
    if(s>=v[r].s1){
        return r;
    }else if(s<v[l].s1){
        return -1;
    }
    while(l<r){
        int mid=(l+r)/2;
        if(v[mid].s1<=s){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    return l;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w", stdout);
    int n;
    int q;
    cin>>n>>q;
    pencil temp;
    for(int i=0;i<n;i++){
        cin>>temp.s1>>temp.s2;
        temp.siz= (temp.s1).size();
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),cmp);
    //testing
    /*for(int i=0;i<v.size();i++){
        cout<<v[i].s1<<" ";
    }
    cout<<endl;*/
    //testing
    int vl=v.size();//number of strings that are used to change
    int fs,ss1s,ss2s;
    string ss1,ss2,temps;
    int ans;
    int s,e;
    int l,r;
    for(int i=0;i<q;i++){
        //for each request
        ans=0;
        cin>>ss1>>ss2;
        ss1s=ss1.size();
        ss2s=ss2.size();
        if(ss1s!=ss2s){
            cout<<"0"<<endl;
            continue;
        }
        s=-1;
        e=-1;
        //find index of longest unmatched;
        for(int j=0;j<ss1s;j++){
            if(s==-1 && ss1[j]!=ss2[j]){
                s=j;
            }
            if(ss1[j]!=ss2[j]){
                e=j;
            }
        }
       // cout<<i<<" "<<s<<" "<<e<<endl;//correct
        for(int j=0;j<=s;j++){
            temps=ss1.substr(j,e-j+1);
            l=lb(temps,0,vl-1);
            //cout<<l<<" ";
            r=ub(temps,0,vl-1);//l,r are for the vector; s,e is for string
            //cout<<r<<endl;
            if(l==-1){
                continue;
            }
            for(int k=l;k<vl;k++){
                //see if can
                if(v[k].siz>ss1s-j){
                    break;
                }
                if((v[k].s1).substr(0,e-j+1)!=ss1.substr(j,e-j+1)){
                    break;
                }
                if(ss1.substr(j,v[k].siz)!=v[k].s1){
                    continue;
                }
                temps=ss1;
                temps.erase(j,v[k].siz);
                temps.insert(j,v[k].s2);
                if(temps==ss2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}