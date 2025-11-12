#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,k; 
const int M=3e6+7;
vector<int>bz[M];
struct node
{
	int l,r;
}seg[N];
int a[N];
int cnt;
int s[N];
bool cmp(node xx,node yy)
{
	if(xx.r!=yy.r)
	return xx.r<yy.r;
	return xx.l<yy.l;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);	
		s[i]=s[i-1]^a[i];
		bz[s[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		int mb=s[i-1]^k;
		
		int len=bz[mb].size()-1;
		if(len==-1||bz[mb][len]<i)
		continue;


		int l=0,r=len;
		int ax;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(bz[mb][mid]<i)
			l=mid+1;
			else
			{
				r=mid-1;
				ax=mid;
			}
		}
		seg[++cnt].l=i;
		seg[cnt].r=bz[mb][ax];
	}
	sort(seg+1,seg+cnt+1,cmp);
	if(cnt==0)
	{
		printf("0");
		return 0;
	}
	int lst=0;
	int ans=0;
	for(int i=1;i<=cnt;i++)
	{
		if(seg[i].l>lst)
		{
			ans++;
			lst=seg[i].r;
		}
	}
	printf("%d",ans);
	return 0; 
}

