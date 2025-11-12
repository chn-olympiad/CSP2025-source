#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e2+10;
int n,m;
int sc[N];
int a,al;
int as;
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>sc[i];
    }
    as=sc[1];
    sort(sc+1,sc+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(sc[i]==as) a=i;
    }
    if(a%n==0)al=a/n;
    else al=a/n+1;
    cout<<al<<" ";
    if(al%2==1){
        if(a%n)cout<<a%n;
        else cout<<n;
    }else{
        if(a%n)cout<<n-a%n+1;
        else cout<<n;
    }
    fclose(stdout);
    return 0;
}
