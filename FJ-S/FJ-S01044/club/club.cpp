#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;

int T;
int n;
int b[N][4];
int c[N];
int k[4];

int s[N];
int ans;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T--)
	{
		memset(k, 0, sizeof(k));
		memset(s, 127, sizeof(s));
		vector<int> all[4];
		ans=0;
		scanf("%d", &n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				scanf("%d", b[i]+j);
		for(int i=1;i<=n;i++)
		{
			if(b[i][1]>=max(b[i][2], b[i][3])){
				ans+=b[i][1];
				c[i] = 1;
				k[1]++;
				all[1].push_back(i);
				continue;
			}
			if(b[i][2]>=max(b[i][1], b[i][3])){
				ans+=b[i][2];
				c[i] = 2;
				k[2]++;
				all[2].push_back(i);
				continue;
			}
			if(b[i][3]>=max(b[i][2], b[i][1])){
				ans+=b[i][3];
				c[i] = 3;
				k[3]++;
				all[3].push_back(i);
				continue;
			}
		}
		//cout << ans << 's' << endl;
		int k1, k2, k3;
		if(k[1]>max(k[2], k[3])){
			k1=1;k2=2;k3=3;
		}
		if(k[2]>max(k[1], k[3])){
			k1=2;k2=1;k3=3;
		}
		if(k[3]>max(k[2], k[1])){
			k1=3;k2=2;k3=1;
		}
		if(k[k1]>n/2)
		{
			for(auto e : all[k1])
			{
				s[e] = b[e][k1]-max(b[e][k2], b[e][k3]);
			}
			sort(s+1, s+n+1);
			for(int i=1;i<=k[k1]-n/2;i++)
			{
				//cout << s[i] << endl;
				ans-=s[i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
