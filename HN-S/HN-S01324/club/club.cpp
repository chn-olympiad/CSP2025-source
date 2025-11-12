#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int N=2e5+5;
int n,val[N][3],cnt[3],pos[N],oth[N],ans;
priority_queue<int>pq;

void Work()
{
	cin>>n;
	cnt[0]=cnt[1]=cnt[2]=ans=0;
	while(pq.empty()==false)
		pq.pop();
	for(int i=1;i<=n;i++)
	{
		cin>>val[i][0]>>val[i][1]>>val[i][2];
		ans+=max({val[i][0],val[i][1],val[i][2]});
		if(val[i][0]>val[i][1]&&val[i][0]>val[i][2])
			cnt[0]++,pos[i]=0;
		else if(val[i][1]>val[i][2])
			cnt[1]++,pos[i]=1;
		else
			cnt[2]++,pos[i]=2;
		if(pos[i]==0)
			oth[i]=max(val[i][1],val[i][2]);
		else if(pos[i]==1)
			oth[i]=max(val[i][0],val[i][2]);
		else
			oth[i]=max(val[i][0],val[i][1]);
	}
	int j=-1;
	if(cnt[0]>(n>>1))
		j=0;
	else if(cnt[1]>(n>>1))
		j=1;
	else if(cnt[2]>(n>>1))
		j=2;
	if(j==-1)
	{
		cout<<ans<<"\n";
		return ;
	}
	int num=0;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		if(pos[i]!=j)
		{
			ans+=val[i][pos[i]];
			continue;
		}
		if(num<(n>>1))
		{
			ans+=val[i][j];
			num++;
			pq.push(oth[i]-val[i][j]);
//			cerr<<"Push "<<oth[i]-val[i][j]<<"\n";
		}
		else
		{
			if(oth[i]>val[i][j]+pq.top())
				ans+=oth[i];
			else
			{
				ans+=val[i][j]+pq.top();
//				cerr<<"Pop "<<pq.top()<<"\n";
				pq.pop();
				pq.push(oth[i]-val[i][j]); 
//				cerr<<"Push "<<oth[i]-val[i][j]<<"\n";
			}
		}
	}
	cout<<ans<<"\n";
	return ;
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)
		Work();
	return 0;
}
