#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){return x>y;}
int a[102];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m,c,r,t,k,z;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            k=i;break;
        }
    }
    // cout<<k<<endl;
    c=(k+n-1)/n;
    if(c%2==1)r=k%n;
    else r=n-(k%n)+1;
    if(r==0)r=n;
    cout<<c<<" "<<r<<"\n";
    return 0;
}