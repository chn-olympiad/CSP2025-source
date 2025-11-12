#include<algorithm>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
#define cin lyc
#define cout lmy
//cin loves cout!
ifstream cin("club.in");
ofstream cout("club.out");
vector<int> club[5],tmp;
int n,a[100005][5];
long long ans;
void mian()
{
	ans=0;
	club[1].clear();
	club[2].clear();
	club[3].clear();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int mx=max(max(a[i][1],a[i][2]),a[i][3]);
		if(a[i][1]==mx)			club[1].push_back(i),ans+=a[i][1];
		else if(a[i][2]==mx)	club[2].push_back(i),ans+=a[i][2];
		else if(a[i][3]==mx)	club[3].push_back(i),ans+=a[i][3];
	}
	for(int j=1;j<=3;j++)
		if(club[j].size()>n/2)
		{
			tmp.clear();
			for(int i:club[j])
			{
				int mx=-1e9;
				for(int k=1;k<=3;k++)
					if(k!=j)
						mx=max(mx,a[i][k]-a[i][j]);
				tmp.push_back(mx);
			}
			sort(tmp.begin(),tmp.end(),greater<int>());
			for(int i=n/2;i<club[j].size();i++)
				ans+=tmp[i-n/2];
		}
	cout<<ans<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)	mian();
}