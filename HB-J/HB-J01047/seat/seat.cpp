#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010];
bool cmp(int x,int y){return x>y;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int l=n*m;
    for(int i=1;i<=l;i++) cin>>a[i];
    int r=a[1];
    sort(a+1,a+l+1,cmp);
    for(int i=1;i<=l;i++) if(a[i]==r){r=i;break;}
    int a1=r/n+1,a2=r%n;
    if(r%n==0) a1--;
    if(a2==0) a2=n;
    if(a1%2==1) cout<<a1<<" "<<a2;
    else cout<<a1<<" "<<n-a2+1;
    return 0;
}
