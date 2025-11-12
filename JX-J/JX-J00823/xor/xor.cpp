#include<bits/stdc++.h>
using namespace std;
string to(int t){
    string er;
    while(t>0){
        er=to_string(t%2)+er;
        t/2;
    }
    er=to_string(t)+er;
    return er;
}
int bac(string to){
    int a=1;
    for(int i=1;i<to.length()+1;i++){
        a*=2;
        if(to[i]=='1'){
            a+=1;
        }
    }
    return a;
}
string yior(string a,string b){
    string jieguo;
    string s;
    int sa=a.size(),sb=b.size();
    bool ad=sa>sb;
    for(int i=min(sa,sb)-1;i>=0;i++){
        if(stoi(a[i]+"")+stoi(b[i]+"")==0){
            jieguo="1"+jieguo;
        }
        else jieguo="0"+jieguo;
    }
    if(ad){
        for(int i=sb;i<sa-1;i++){
            jieguo=a[i]+jieguo;
        }
    }
    else{
        for(int i=sa;i<sb-1;i++){
            jieguo=b[i]+jieguo;
        }
    }
    return jieguo;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,l,r,m,c=0;
    vector<bool> b;
    vector<string> ok;
    vector<string> a;
    vector<string> ab;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>m;
        a.push_back(to(m));
        b.push_back(0);
    }
    ab=a;
    for(l=0;l<n;l++){
        for(r=0;r<n;r++){
            for(int w=l;w<r;w++){
                a[w+1]=yior(a[w],a[w+1]);
            }
            if(bac(a[r])==k){
                c++;
            }
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
