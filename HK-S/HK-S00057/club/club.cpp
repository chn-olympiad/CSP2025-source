#include <bits/stdc++.h>
using namespace std;
struct pencil{
    int val;
    int minu;
};
vector <pencil> v1;
vector <pencil> v2;
vector <pencil> v3;
bool cmp(pencil a,pencil b){
    return a.minu<b.minu;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w", stdout);
    int t;
    cin>>t;
    int n;
    int temp1,temp2,temp3;
    long long ans;
    int vs;
    pencil temp;
    for(int i=0;i<t;i++){
        ans=0;
        cin>>n;
        //input
        for(int j=0;j<n;j++){
            cin>>temp1>>temp2>>temp3;
            if(temp1>=temp2 && temp1>=temp3){
                temp.val=temp1;
                temp.minu=temp1-max(temp2,temp3);
                v1.push_back(temp);
            }else if(temp2>=temp1 && temp2>=temp3){
                temp.val=temp2;
                temp.minu=temp2-max(temp1,temp3);
                v2.push_back(temp);
            }else{
                temp.val=temp3;
                temp.minu=temp3-max(temp2,temp1);
                v3.push_back(temp);
            }
        }
        //do the thing
        if(int(v1.size())>n/2){
            sort(v1.begin(),v1.end(),cmp);
            while(int(v1.size())>n/2){
                ans+=v1[0].val-v1[0].minu;
                v1.erase(v1.begin());
            }
        }else if(int(v2.size())>n/2){
            sort(v2.begin(),v2.end(),cmp);
            while(int(v2.size())>n/2){
                ans+=v2[0].val-v2[0].minu;
                v2.erase(v2.begin());
            }
        }else if(int(v3.size())>n/2){
            sort(v3.begin(),v3.end(),cmp);
            while(int(v3.size())>n/2){
                ans+=v3[0].val-v3[0].minu;
                v3.erase(v3.begin());
            }
        }
        //output and clear
        vs=v1.size();
        for(int j=0;j<vs;j++){
            ans+=v1[0].val;
            v1.erase(v1.begin());
        }
        vs=v2.size();
        for(int j=0;j<vs;j++){
            ans+=v2[0].val;
            v2.erase(v2.begin());
        }
        vs=v3.size();
        for(int j=0;j<vs;j++){
            ans+=v3[0].val;
            v3.erase(v3.begin());
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
