#include<bits/stdc++.h>
using namespace std;
bool comp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,m,i=1,j=1,a[105]={INT_MIN};
    cin>>n>>m;
    for(int o=1;o<=n*m;o++)
        cin>>a[o];
    int goal=a[1];
    sort(a+1,a+n*m+1,comp);
    for(int cnt=1;cnt<=n*m;cnt++)
    {
        if(a[cnt]==goal) {
            cout<<i<<' '<<j;
            break;
        }
        if(j<n&&i%2==1) {j++;continue;}
        if(j>1&&i%2==0) {j--;continue;}
        if(j=1&&i%2==0) {i++;j=1;continue;}
        if(j=n&&i%2==1) {i++;j=n;continue;}
    }
    return 0;
}
