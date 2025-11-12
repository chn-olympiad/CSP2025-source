#include<bits/stdc++.h>
using namespace std;
int n,a[1001],ans;
 /*void dfs(int x,int l,int k,int p[])
{
    cout<<x<<" "<<l<<" "<<k<<endl;
    if(x==n+1)
    {
        if(l>=3&&p[l]*2<k)
        {

            //if(m[s]!=1)
             //{
                 cout<<"THis:"<<endl;
                for(int i=1;i<=l;i++)
                    cout<<p[i]<<" ";
                cout<<endl;
                 ans++;//m[s]=1;
             //}
        }
        return;
    }
    p[l+1]=a[x];
    dfs(x+1,l+1,k+a[x],p);
    p[l+1]=0;
    dfs(x+1,l,k,p);
}*/
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    /*int p[1001];
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    dfs(1,0,0,p);
    cout<<ans<<endl;*/
    int a,b,c;
    cin>>n;
    cin>>a>>b>>c;
    if(a+b>c&&a+c>b&&b+c>a)
        cout<<1<<endl;
    else
        cout<<0<<endl;
}
