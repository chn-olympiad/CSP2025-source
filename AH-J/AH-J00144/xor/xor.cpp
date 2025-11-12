#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long n,k,x_r[MAXN];
long long ans_line; 
long long false_and[MAXN];
long long empty[MAXN];
long long line_number_ans;
struct line
{
	long long start_id;
	long long end_id;
}a[MAXN];
bool T_F(long long x[],long long ans)
{
	for(int i=1;i<=ans;++i)
		if(x[i]>1) return false;
	return true;
}
bool bfs(long long little_put,long long little_number,long long change[])
{
	if(little_number==ans_line) return false;
	bool bx,by;
	if(little_put==0) 
	{
		if(T_F(change,n)) return true;
		return false;
	}
	bx=bfs(little_put,little_number+1,change);
	for(long long i=a[little_number].start_id;i<=a[little_number].end_id;++i)
		change[i]++;
	by=bfs(little_put-1,little_number+1,change);
	return bx|by;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k); 
	for(long long i=1;i<=n;++i)
	{
		scanf("%lld",&x_r[i]);
		line_number_ans+=x_r[i];
	}
	if(line_number_ans<=n)
	{
		if(k>1) 
			printf("0");
		else
		{
			if(k==0) 
			{
				line_number_ans=0;
				for(long long i=1;i<=n;++i)
				{
					if(x_r[i]+x_r[i-1]==2) line_number_ans++;
					if(x_r[i]==0) line_number_ans++;
				}
			}
			printf("%lld",line_number_ans);
		}
		return 0;
	}
	long long ans_xor;
	for(long long i=1;i<=n;++i)
	{
		ans_xor=0;
		for(long long j=i;j<=n;++j)
		{
			ans_xor=ans_xor^x_r[j];
			if(ans_xor==k) 
			{
				a[++ans_line].start_id=i;
				a[ans_line].end_id=j;
				false_and[i]++;
				false_and[j+1]--;
			}
		}
	}
	long long l=0,r=ans_line;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(bfs(mid,1,empty))
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	printf("%lld",l);
	return 0;
}
