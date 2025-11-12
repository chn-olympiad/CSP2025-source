#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[505];
bool flag=0;
bool f=0;
string A;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>A;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<A.size();i++){
        if(A[i]=='1') flag=true;
        if(A[i]=='0') f=true;
    }
    if(!flag){
        cout<<0;
        return 0;
    }
    if(m==n&&f){
        cout<<0;
        return 0;
    }
    int sum=1,tmp=n;
    for(int i=1;i<=tmp;i++){
        if(a[i]==0) n--;
    }
    if(n==0){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        sum*=i;
        sum%=998244353;
    }
    cout<<sum;
    return 0;
}
