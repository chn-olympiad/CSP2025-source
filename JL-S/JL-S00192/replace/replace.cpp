#include<bits/stdc++.h>
using namespace std;
char a[200][400],b[200][400],l[200];
char c[400],d[400];
int ll[1100000],lenn[1100000];
char x[1000000],y[10000000];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,i,j,k,ii,len,ans,left,right,lll,rrr,mmm;
    scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%s",a[i]);
            scanf("%s",b[i]);
            l[i]=strlen(a[i]);
        }
        for(i=1;i<=q;i++)
        {
            scanf("%s",c);
            scanf("%s",d);
            len=strlen(c);
            ans=0;
            left=-1;
            for(j=0;j<len;j++)
            {
                if(c[j]==d[j])left++;
                else
                {
                    break;
                }
            }
            right=len;
            for(j=len-1;j>=0;j--)
            {
                if(c[j]==d[j])right--;
                else
                {
                    break;
                }
            }
            for(j=1;j<=n;j++)
            {
                if(l[j]>len)continue;
                for(k=max(right-l[j],0);k+l[j]-1<len&&k<=left+1;k++)
                {
                    for(ii=k;ii<l[j]+k;ii++)
                    {
                        if(c[ii]!=a[j][ii-k]||d[ii]!=b[j][ii-k])break;
                    }
                    if(ii>=l[j]+k)
                    {
                        ans++;
                    }
                }
            }
            printf("%d\n",ans);
        }
    return 0;
}
