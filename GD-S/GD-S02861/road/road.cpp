#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int ma[N][N],c[20],cij[20][N];
int n,m,k;
vector<int> weight;
int main(){
	freopen("road3.in","r",stdin);
//	freopen("road.out","w",stdout);;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int a,b,w;cin>>a>>b>>w;
		ma[a][b]=ma[b][a]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];//=0
		for(int j=1;j<=n;j++)
		{
			cin>>cij[i][j];
			ma[i][j]=min(ma[i][j],cij[i][j]);
		//	weight.push_back(cij[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(ma[i][j]!=0) weight.push_back(ma[i][j]);
		}
	}
	sort(weight.begin(),weight.end());
	int ans=0;
//	for(int i=0;i<weight.size();i++) cout<<weight[i]<<" ";
//	cout<<endl;
//	cout<<n<<endl;
	for(int i=0;i<weight.size() && i<n-1;i++)
	{
		ans+=weight[i];
	}
	cout<<ans;
	return 0;
}
