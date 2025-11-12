#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int pd[N];
struct node{int id=0, ty=0, ns=0;}p[N*3];
int t, n, f[N];
bool cmp(node x, node y)
{ 
	return x.ns>y.ns;
} 

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &t);
	
	while(t--)
	{
		memset(f, 0, sizeof f);
		int cnt[4]={0, 0, 0, 0};
		int ans=0;
		scanf("%d", &n);
		{
			
			for(int i=1; i<=n; i++)
			{
				scanf("%d %d %d", &p[i*3].ns, &p[i*3-1].ns, &p[i*3-2].ns);
				p[i*3].id=p[i*3-1].id=p[i*3-2].id=i;
				p[i*3].ty=1, p[i*3-1].ty=2, p[i*3-2].ty=3;
			}
			sort(p+1, p+n*3+1, cmp);
			int kx=n/2;
			for(int i=1; i<=n*3; i++)
				if(f[p[i].id]==0 && cnt[p[i].ty]<kx) 
					ans+=p[i].ns, f[p[i].id]=1, cnt[p[i].ty]++;
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
