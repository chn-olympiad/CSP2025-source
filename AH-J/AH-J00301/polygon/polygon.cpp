#include<bits/stdc++.h>
using namespace std;
long long N=998244353,M=INT_MIN;
long long n,a[50000],c=0,s=0,maxx=M;
bool check(int s1,int maxx1){
    if(s1>maxx1*2){
        return true;
    }
    else return false;
}
void dfs(int cnt1){
    if(cnt1<=0)return;
    for(int i=1;i<=n-cnt1+1;i++){
        s+=a[i];
        maxx=max(maxx,a[i]);
        dfs(cnt1-1);
    }
    if(check(s,maxx)==true){
        c++;
        c%=N;
        s=0;
        maxx=M;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=3;i--){
        dfs(i);
    }
    cout<<endl;
    cout<<c;
    return 0;
}
