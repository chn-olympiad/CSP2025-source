#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[100005],r;
bool cmp(int a,int b){return a>b;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    r=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)if(a[i]==r){r=i;break;}
    int h=r%(2*n),l=r/(2*n)*2+1;
    if(h==0)h=1,l--;
    else if(h>n)h=2*n-h+1,l++;
    cout<<l<<" "<<h;
    return 0;
}
