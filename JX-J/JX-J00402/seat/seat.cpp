#include <bits/stdc++.h>

using namespace std;
int n,m;
int a[105];
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int l=n*m;
    for(int i=1;i<=l;i++){
        cin>>a[i];
    }
    int t=a[1];int p;
    sort(a+1,a+l+1,cmp);
    for(int i=1;i<=l;i++){
        if(a[i]==t){
            p=i;
        }
    }
    int temp=p/n;
    if(temp<1){
        cout<<1<<" "<<p;
        return 0;
    }
    if(temp%2==1){
        if(p-temp*n==0){
            cout<<temp<<" "<<n;
            return 0;
        }
        cout<<temp+1<<" "<<temp*n+n-p+1;
        return 0;
    }
    if(temp%2==0){
        if(p-temp*n==0){
            cout<<temp<<" "<<1;
            return 0;
        }
        cout<<temp+1<<" "<<p-temp*n;
        return 0;
    }
    return 0;
}
