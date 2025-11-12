#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
const int N=1e5+7;
int n,m,a[N];
bool cmp(int a,int b){return a>b;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int x=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)if(a[i]==x){x=i;break;}
    int l=(x-1)*1.0/n+1,h=(x-1)%n+1;
    if(l%2==0)h=n-h+1;
    cout<<l<<' '<<h;
    return 0;
}
