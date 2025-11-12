#include <bits/stdc++.h>
using namespace std;
struct Student{
	int max_pos,min_pos,sum,maxn,minn;
}t[100005]; 
bool cmp(Student x,Student y)
{
	return x.maxn+y.sum-y.maxn-y.minn>y.maxn+x.sum-x.maxn-x.minn;
}
int T,n,sum[5],ans,a,b,c;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club,out","w",stdout);
	cin>>T;
	while (T--)
	{
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a>>b>>c;
			t[i].sum=a+b+c;
			if (max(a,max(b,c))==a){t[i].max_pos=1;t[i].maxn=a;}
			if (max(a,max(b,c))==b){t[i].max_pos=2;t[i].maxn=b;}
			if (max(a,max(b,c))==c){t[i].max_pos=3;t[i].maxn=c;}
			if (min(a,min(b,c))==a){t[i].min_pos=1;t[i].minn=a;}
			if (min(a,min(b,c))==b){t[i].min_pos=2;t[i].minn=b;}
			if (min(a,min(b,c))==c){t[i].min_pos=3;t[i].minn=c;}
		}
		sort(t+1,t+n+1,cmp);
		for (int i=1;i<=n;i++)
		{
			if (sum[t[i].max_pos]<n/2){
				ans+=t[i].maxn;
				sum[t[i].max_pos]++;
			}
			else
			{
				ans+=t[i].sum-t[i].maxn-t[i].minn;
				sum[6-t[i].max_pos-t[i].min_pos]++;
			}
		}
		cout<<ans;
		sum[1]=sum[2]=sum[3]=ans=0;
	}
 } 
