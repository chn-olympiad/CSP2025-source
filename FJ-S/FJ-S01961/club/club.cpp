#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;

int a[N][3];

struct node{
	int a,dt;
	
	bool operator<(node b)const {
		return dt<b.dt;
	}
};

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;cin>>T;
	while(T--)
	{
		int n;cin>>n;
		
		for(int i=1;i<=n;i++)
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		
		vector<node> res[3];
		
		for(int i=1;i<=n;i++)
		{
			int x=0,dt=0;
			for(int j=0;j<3;j++)
				if(a[i][j]>a[i][x])
					x=j;
			
			int c_max=0;
			for(int j=0;j<3;j++)
				if(j!=x)
					c_max=max(c_max,a[i][j]);
			dt=a[i][x]-c_max;
			
			res[x].push_back({a[i][x],dt});
		}
		
		int ans=0;
		for(int j=0;j<3;j++)
			for(auto it=res[j].begin();it!=res[j].end();it++)
				ans+=it->a;
		
		for(int j=0;j<3;j++)
			if((int)res[j].size()>n/2)
			{
				sort(res[j].begin(),res[j].end());
				int l=res[j].size()-n/2;
				for(int i=0;i<l;i++)
					ans-=res[j][i].dt;
			}
		cout<<ans<<endl;
	}
	return 0;
}
