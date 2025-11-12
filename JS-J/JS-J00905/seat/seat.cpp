#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b) {
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int x=a[1],i=1,j=1,d=1;
    sort(a+1,a+n*m+1,cmp);
    for(int k=1;k<=n*m;k++){
        if(a[k]==x){
            cout<<j<<' '<<i;
            return 0;
        }
        i+=d;
        if(i>n){
            j++;
            d=-1;
            i=n;
        }
        if(i<1){
            j++;
            d=1;
            i=1;
        }
    }
    return 0;
}
