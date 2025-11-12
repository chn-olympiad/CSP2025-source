#include<iostream>
using namespace std;
int comp,n=0,k=0,a[600005],ansx,gc;
void tp(int dep,int ans)
{
    if(dep>=n)
    {
        if(a[dep]==k)ans++;
        ansx=max(ans,ansx);
        return;
    }
    else
    {
        if(a[dep]==k)
            tp(dep+1,ans+1);
        else
        {
            gc=a[dep];
            for(int i=dep+1; i<=n; i++)
            {
                gc=(gc xor a[i]);
                if(gc==k)
                    tp(i+1,ans+1);
            }
            tp(dep+1,ans);
        }

    }

}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    a[n+1]=-1;
    tp(1,0);
    cout<<ansx;
    return 0;
}
