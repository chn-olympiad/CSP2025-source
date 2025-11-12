#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using VI=vector<int>;
using PII=pair<int,int>;
#define MP make_pair
#define fi first
#define se second
#define PB emplace_back
#define PPB pop_back
#define endl ('\n')
#define ALL(x) (x).begin(),(x).end()

const int N=100005;
int n,a[N][3];
VI f[3];

int main()
{
#ifndef LOCAL
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
#endif
	ios::sync_with_stdio(false),cin.tie(nullptr);

	int _;cin>>_;while(_--)
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2],f[max_element(a[i],a[i]+3)-a[i]].PB(i);
	int ans=0;
	for(int i=0;i<3;i++)
	{
		for(int j:f[i])ans+=a[j][i];
		if(f[i].size()>(n>>1))
		{
			VI mns;
			for(int j:f[i])
				mns.PB(a[j][i]-max(a[j][(i+1)%3],a[j][(i+2)%3]));
			sort(ALL(mns));
			for(int j=0;j<f[i].size()-(n>>1);j++)ans-=mns[j];
		}
	}
	cout<<ans<<endl;

	for(int i=0;i<3;i++)f[i].clear();
}

	return 0;
}