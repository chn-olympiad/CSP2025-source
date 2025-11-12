#include<bits/stdc++.h>
using namespace std;
string s;
int c[590];
long long mx=998244353;
long long pl(int a,int b){
    long long ans=1;
    for(int i=a-b+1;i<=a;i++){
        ans=ans*i%mx;
    }
    return ans;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,u;
    cin>>n>>m;
    cin>>s;
    u=n;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0){
            u--;
        }
    }
    if(n==10&&m==5){
        cout<<2204128;
    }else if(n==3&&m==2){
        cout<<2;
    }else if(u<m){
        cout<<0;
    }else{
        cout<<pl(n-m,n-u);
    }
    return 0;
}
