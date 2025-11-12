#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    int a[225];
    int b[15][15];
    int n,m,ans,l;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    ans=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            if(i%2==0) l=a[i*m+j];
            else l=a[i*m+(m-j)+1];
            if(l==ans){
                cout<<i+1<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}
