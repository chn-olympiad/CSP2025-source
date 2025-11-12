#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100000;
int T,n,cnt[4],ans;

struct node
{
	int s,ci;
}d[5],p[N+10][5],s[N+10];

bool operator < (const node &p1,const node &p2){
	return p1.s < p2.s;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin>>T;
	while(T--)
	{
		cin>>n;
		ans = 0; 
		cnt[1] = cnt[2] = cnt[3] = 0 ;
		
		for(int i=1,a,b,c;i<=n;i++)
		{
			cin>>a>>b>>c;
			d[1] = {a,1};
			d[2] = {b,2};
			d[3] = {c,3};
			sort(d+1,d+1+3);
			
			for(int j=3;j>=1;j--)
				p[i][4-j] = d[j];
				
			ans += p[i][1].s;
			cnt[p[i][1].ci]++;
			
			s[i] = {(p[i][1].s - p[i][2].s), p[i][1].ci};
		}
		
		sort(s+1,s+1+n);
		
		for(int i=1;i<=n;i++)
		{
			if(cnt[s[i].ci] > n/2)
			{
				ans -= s[i].s;
				cnt[s[i].ci]--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
