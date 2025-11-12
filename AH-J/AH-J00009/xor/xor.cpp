#include<bits/stdc++.h>
using namespace std;
int num[10005];
struct node1
{
     int x,y,used;
}a[10005];
int b[10005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,cnt1=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    for(int i=1;i<=n;i++)
    {
		if(num[i]==k)
		{
			 a[++cnt1]={i,i};
			 continue;
		}
        int _xor=num[i],j;
        for(j=i+1;j<=n;j++)
        {
               _xor=_xor^num[j];
               if(_xor==k) break;
        }
        if(j<=n) a[++cnt1]={i,j};
    }
    for(int i=1;i<=cnt1;i++)
    {
		if(!a[i].used) b[i]=1;
	    int mn=2e9,mni=0;
        for(int j=i+1;j<=cnt1;j++)
            if(a[j].x>a[i].y&&a[j].y<mn)
                 mn=a[j].y,mni=j;
        if(mn!=2e9)
        {
			a[mni].used=1;
			b[mni]=max(b[mni],b[i]+1);
		}
    }
    int ans=0;
    for(int i=1;i<=cnt1;i++)
         ans=max(ans,b[i]);
    printf("%d",ans);
    return 0;
}
