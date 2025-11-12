#include<bits/stdc++.h>
using namespace std;
int n,i,j,maxn,tot;
int a[4];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n==3)
    {
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        tot+=a[i];
    }
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
        {
            if(a[i]<a[j])
                swap(a[i],a[j]);
        }
     maxn=2*a[1];
     if(tot>2*a[1])
     cout<<1;
     else cout<<0;
    }
        fclose(stdin);
        fclose(stdout);
     return 0;
}
