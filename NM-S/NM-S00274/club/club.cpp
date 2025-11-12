#include<bits/stdc++.h>
using namespace std;
const int N=20005;
int t,n;
int fa,fb,fc;
long long ans;
int a,b,c;


int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%d",&n);
        fa=0;
        fb=0;
        fc=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a,&b,&c);
            if(a>=b&&a>=c&&2*fa<=n)ans+=a,fa++;
            else if(b>=c&&2*fb<=n)ans+=b,fb++;
            else ans+=c,fc++;
        }
        cout<<ans;
    }
    return 0;
}
