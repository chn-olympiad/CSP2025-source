#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005],x,y,z,p,sum;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    cin>>n;
    int m,r,t;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        if((m+r+t==n)&&(m!=0)&&(r!=0)&&(t!=0)&&(m<=n/2)&&(r<=n/2)&&(t<=n/2)){
            p++;
        }
        for(int i=1;i<=m;i++){
            x+=a[i];
        }
        for(int i=1;i<=r;i++){
            y+=b[i];
        }
        for(int i=1;i<=t;i++){
            z+=c[i];
        }
    }
    sum=x+y+z;
    for(int i=1;i<=p;i++){
        cout<<sum<<endl;
    }
    return 0;
}
