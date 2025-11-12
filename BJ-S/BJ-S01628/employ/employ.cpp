#include<bits/stdc++.h>
//#define LOCAL
using namespace std;
const int mod=998244353;
int a[1001],getmax[1001];
int main(){
#ifndef LOCAL
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
#endif
    int n,m;
    string s;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    getmax[n+1]=0;
    for(int i=n;i>0;i--){
        getmax[i]=max(a[i],getmax[i+1]);
    }
    bool flag=true;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            flag=false;
            break;
        }
    }
    if(flag){
        cout<<0;
        return 0;
    }
    if(n<10){
        vector<int> v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        int ans=0;
        do{
            int cnt=0,fq=0;
            for(int i=0;i<v.size();i++){
                if(fq>=a[v[i]]){
                    fq++;
                    continue;
                }
                if(fq>=getmax[v[i]]){
                    break;
                }
                if(s[i]=='0')fq++;
                else cnt++;
            }
            if(cnt>=m)ans++;
            ans%=mod;
        }while(next_permutation(v.begin(),v.end()));
        cout<<ans;
        return 0;
    }
    cout<<0;
    return 0;
}
/*
Problem Est.
club    20pts
road    0-16pts
replace 0-20pts
employ  40pts
Tot. 60-96pts
Maybe second. First is realllllllllllllllllllllly hard. I want to ***k *c*.
Questions' hardness:
Yellow-Green, Green, Blue, Black/Purple.
*/
