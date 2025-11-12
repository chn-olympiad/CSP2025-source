#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m;
string s;
int a0[100001];
int a[100001];
signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);	
    cin>>n>>m;
    cin>>s;
    a0[0]=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            a0[i+2]++;
        }
        a0[i+1]+=a0[i];
    }
    int f=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a0[i]!=0){
            f=1;
        }
        
    }
    if(f==0||(m==n&&(a0[n]==0))){
        int res=1;
        for(int i=2;i<=n;i++){
            res*=i;
            res%=mod;
        }
        cout<<res<<endl;
        return 0;
    }
    if(m==n&&a0[n]!=0){
        cout<<"0"<<endl;
    }
    return 0;
}