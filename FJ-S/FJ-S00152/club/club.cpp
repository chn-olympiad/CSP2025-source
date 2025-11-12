#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
int t;
struct as{
	int a,b,c;
}z[1000100],zz[1000100];
int st[1000010];
map<int,int>mp;
int mx=-INF;
int n;
void dfs(int sum,int cnt){
	if(cnt==n+1){
		mx=max(mx,sum);
		return ;
	}
	for(int j=cnt;j<=n;j++){
		for(int i=1;i<=3;i++){
			if(mp[i]!=n/2){
				mp[i]++;
				if(i==1) sum+=z[j].a;
				else if(i==2) sum+=z[j].b;
				else if(i==3) sum+=z[j].c;
				dfs(sum,j+1);
				if(i==1) sum-=z[j].a;
				else if(i==2) sum-=z[j].b;
				else if(i==3) sum-=z[j].c;
				mp[i]--;
			}
		}
	}
	
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		mp.clear();
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>z[i].a>>z[i].b>>z[i].c;
		}
		mx=-INF;
		dfs(0,1);
		cout<<mx<<endl;
	}

	return 0;     
} 

