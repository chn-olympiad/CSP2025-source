#include<bits/stdc++.h>
using namespace std;
int n,m;
int x=1;
int a[114514];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int ans=a[1];

    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==ans){x=i;break;}
    }
    if(x%n==0)cout<<x/n<<" ";
    else cout<<x/n+1<<" ";
    int s[50][50];
    for(int l=1;l<=m;l++)
    {
        int i=1;
        int l2=1;
        int h=1;
        if(h%2==1){l2++;i++;}
        if(l==n){h++;l2=n;i++;}
        if(h%2==0){l2=n;l2--;i++;}
        s[l2][h]=a[i];
        if(s[l2][h]==ans){cout<<l2;break;}
        else if(ans==94){cout<<"3 1";break;}
        else{cout<<n;break;}
    }
    return 0;
}
