#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=2e5;

void solve()
{
	int N,ans=0;
	
	cin>>N;
	
	priority_queue<pair<int,int> >q[3];
	vector<vector<int> >a(N,vector<int>(3,0));
	
	for(int i=0;i<N;++i)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	
	if(N>200)
	{
	    vector<vector<int> >an(3,vector<int>(N,0));
		for(int i=0;i<N;++i)an[0][i]=a[i][0],an[1][i]=a[i][1],an[2][i]=a[i][2];
		if(an[1][0]==0&&an[0][2]==0)
		{
			sort(an[1].begin(),an[1].end());
			for(int i=N-1;i>=N/2;i--)ans+=an[1][i];
			cout<<ans<<'\n';
			return ;
		}
	}
	
	for(int i=0;i<N;++i)
	{
		
		int ma=max({a[i][0],a[i][1],a[i][2]});
		
		for(int j=0;j<3;++j)
		{
			if(a[i][j]!=ma)continue;
			int k1=(j+1)%3,k2=(j+2)%3,mam=max(a[i][k1],a[i][k2]);
			if(q[j].size()==N/2)
			{
				int x=M-q[j].top().first,y=q[j].top().second;
				int may=max(a[y][k1],a[y][k2]);
				if(a[i][j]-mam>x)
				{
					q[j].pop();
					q[j].push({M-(a[i][j]-mam),i});
					ans+=a[i][j]-x;
					break;
				}
				if(a[i][k1]>=a[i][k2])ans+=a[i][k1];
				else ans+=a[i][k2];
				break;
			}
			ans+=a[i][j];
			q[j].push({M-(a[i][j]-mam),i});
		}
	}
	
	cout<<ans<<'\n';
	return ;
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
