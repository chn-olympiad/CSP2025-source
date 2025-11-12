#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int a[100010];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int qb=0;
    for(int i=1;i<=n*m;i++)
    {

        cin>>a[i];
    }
    qb=a[1];
    int nb=0;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==qb)
        {
            nb=i;
        }
    }
    int ret=0;
    while(nb>n)
    {
        nb-=n;
        ret++;
    }
    cout<<ret+1<<" ";
    if((ret+1)%2==1)
    {
        cout<<nb;
    }
    else
    {
        cout<<n-nb%n+1;
    }
    return 0;
}
