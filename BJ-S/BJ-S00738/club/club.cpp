#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int T,n,ans;
vector<int> t[5];
struct ss
{
	int fir,sec,thi,ma1,ma2;
}a[N];
priority_queue<int,vector<int>,greater<int>> pq;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].fir>>a[i].sec>>a[i].thi;
			if(a[i].fir<a[i].thi&&a[i].sec<a[i].thi) a[i].ma1=3;
			else if(a[i].fir<a[i].sec&&a[i].sec>a[i].thi) a[i].ma1=2;
			else a[i].ma1=1;
			t[a[i].ma1].push_back(i);
			a[i].ma2=max(a[i].fir,a[i].sec);
			a[i].ma2=max(a[i].ma2,a[i].thi);
			ans+=a[i].ma2;
		}
		for(int i=1;i<=3;i++)
		{
			int siz=t[i].size();
			if(siz>n/2)
			{
				for(int j=0;j<siz;j++)
				{
					int k=t[i][j],cha;
					if(a[k].ma1==1) cha=min(a[k].ma2-a[k].sec,a[k].ma2-a[k].thi);
					else if(a[k].ma1==2) cha=min(a[k].ma2-a[k].fir,a[k].ma2-a[k].thi);
					else cha=min(a[k].ma2-a[k].sec,a[k].ma2-a[k].fir);
					pq.push(cha);
				}
				while(siz>n/2)
				{
					int x=pq.top();
					pq.pop();
					ans-=x;
					siz--;
				}
				break;
			}
		}
		cout<<ans<<endl;
		while(!pq.empty()) pq.pop();
		for(int i=1;i<=3;i++) t[i].resize(0);
	}
	return 0;
}
