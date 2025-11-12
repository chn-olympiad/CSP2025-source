#include<bits/stdc++.h>
using namespace std;

int t,n,ans;
int a[100010],aa,b[100010],bb,c[100010],cc;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    int x1,x2,x3;
    while(t--)
    {
        ans=aa=bb=cc=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&x1,&x2,&x3);
            int maxx=max(x1, max(x2,x3) );
            int minn=min(x1, min(x2,x3) );
            ans+=maxx;
            if(x1>=x2&&x1>=x3)
            {
                aa++;
                a[aa]=maxx- (x1+x2+x3-maxx-minn);
            }
            if(x2>=x1&&x2>=x3)
            {
                bb++;
                b[bb]=maxx- (x1+x2+x3-maxx-minn);
            }
            if(x3>=x2&&x3>=x1)
            {
                cc++;
                c[cc]=maxx- (x1+x2+x3-maxx-minn);
            }
        }
        if(aa>n/2)
        {
            sort(a,a+aa);
            for(int i=1;i<=aa-n/2;i++)
            {
                ans-=a[i];
            }
        }
        if(bb>n/2)
        {
            sort(b,b+bb);
            for(int i=1;i<=bb-n/2;i++)
            {
                ans-=b[i];
            }
        }
        if(aa>n/2)
        {
            sort(c,c+cc);
            for(int i=1;i<=cc-n/2;i++)
            {
                ans-=c[i];
            }
        }
        printf("%d\n",ans);
    }


    return 0;
}
