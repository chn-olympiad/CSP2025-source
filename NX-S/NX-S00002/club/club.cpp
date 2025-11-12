#include<bits/stdc++.h>
using namespace std;
int t;
struct jb
{
   int a,b,c;
   int mx,nu;
};
jb sy[100010];
jb keg[100010];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int n,ans=0;
        cin>>n;
        int p=n/2;
        int ap,bp,cp=0;
        for(int i=1;i<=n;i++)
        {
            int a,b,c=0;
            cin>>a>>b>>c;
            if(a>=b&&b>=c) ans=ans+a,ap++;
            else if(a>=c&&c>=b) ans=ans+a,ap++;
            else if(b>=a&&a>=c) ans=ans+b,bp++;
            else if(b>=c&&c>=a) ans=ans+b,bp++;
            else if(c>=b&&b>=a) ans=ans+c,cp++;
            else if(c>=a&&a>=b) ans=ans+c,cp++;
        }
        if(ap<=n/2&&bp<=n/2&&cp<=n/2) cout<<ans;
        else cout<<ans-1;
    }
    return 0;

}

