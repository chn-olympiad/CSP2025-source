#include<bits/stdc++.h>
using namespace std;
int a[101][101],b[1001];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r,sl;cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>b[i];
    r=b[1];
    for(int i=1;i<n*m;i++){
        for(int j=i+1;j<=n*m;j++)
            if(b[i]<b[j])
                swap(b[i],b[j]);
        if(b[i]==r)
        {
            sl=i;break;
        }
    }
    if(((sl-1)/n)%2!=1)
        cout<<(sl-1)/n+1<<" "<<(sl-1)%n+1;
    else
        cout<<(sl-1)/n+1<<" "<<(n+1-(sl%n));
    return 0;
}
