#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k,a[N][5],j[N],cnt[3];
vector<int> v;



int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int ttt;  scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d",&n),k=n/2;
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",a[i]+0,a[i]+1,a[i]+2);
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2])j[i]=0;
			else if(a[i][1]>a[i][2])j[i]=1;
			else j[i]=2;
			sum+=a[i][j[i]];
			cnt[j[i]]++;
		}
		int f=-1;
		if(cnt[0]>k)f=0;
		else if(cnt[1]>k)f=1;
		else if(cnt[2]>k)f=2;
		if(f!=-1)
		{
			for(int i=1;i<=n;i++)if(j[i]==f)
			{
				v.emplace_back(a[i][j[i]]-max(a[i][(j[i]+1)%3],a[i][(j[i]+2)%3]));
			}
			sort(v.begin(),v.end());
			for(int i=0;i<cnt[f]-k;i++)sum-=v[i];
			v.clear();
		}
		printf("%lld\n",sum);
		cnt[0]=cnt[1]=cnt[2]=0;
	}
	return 0;
}
