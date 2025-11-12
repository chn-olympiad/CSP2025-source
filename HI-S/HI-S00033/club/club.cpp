#include <bits/stdc++.h>
#define _F(x,y,z) for(int x=y;x<=z;x++)
#define F_(x,y,z) for(int x=y;x>=z;x--)
#define TF(x,y,z) for(int x=head[y],z,;x;x=nex[x])

using namespace std;

typedef long long ll;
typedef const int ci;
typedef double dou;
typedef pair<int,int> pii;

ci maxn=2e6+10;
int n,a[maxn][4],cnt[4],tg[maxn];
int res=0;
priority_queue<int>pq;
void work()
{
    while(!pq.empty())pq.pop();
	scanf("%d",&n);
	cnt[1]=cnt[2]=cnt[3]=0;res=0;
	_F(i,1,n)
	{
	    int t=1;
	    _F(j,1,3)
        {
            scanf("%d",&a[i][j]);
            if(a[i][t]<a[i][j])
                t=j;
        }
        cnt[t]++;tg[i]=t;
        res+=a[i][t];
	}
//        printf("%d\n",res);
	int fl=0;
	_F(i,1,3)
        if(cnt[i]>n/2)
            fl=i;
    if(!fl)
    {
        printf("%d\n",res);
        return ;
    }
    _F(i,1,n)
    {
        if(tg[i]!=fl) continue;
        int mn=11451419;
        _F(j,1,3)
        {
            if(j!=fl)
                mn=min(mn,a[i][fl]-a[i][j]);
        }
//        printf("%d\n",mn);
            pq.push(-mn);
    }
    while((int)pq.size()>n/2)
    {
        res+=pq.top();pq.pop();
    }
    printf("%d\n",res);
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
		work();
	fclose(stdin);
	fclose(stdout);
}
//done on 15:11

