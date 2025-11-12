#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> b[3];
int a[N][3],n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		b[0].clear(),b[1].clear(),b[2].clear();
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int mx=-1e9;
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
				mx=max(mx,a[i][j]);
			}
			ans+=mx;
		//	cout<<i<<' '<<mx<<endl;
			for(int j=0;j<3;j++)
			{
				if(a[i][j]==mx)
				{
					int mx1=-1e9;
					for(int k=0;k<3;k++)
						if(j^k) mx1=max(mx1,a[i][k]); 
					b[j].push_back(mx-mx1);
					break;
				}
			}
		}
	//	cout<<ans<<'\n';
		for(int i=0;i<3;i++)
		{
			
			if(b[i].size()>n/2)
			{
				sort(b[i].begin(),b[i].end());
				for(int j=0;j<b[i].size()-n/2;j++)
					ans-=b[i][j];
			}
		}
		cout<<ans<<'\n';
	}
}
