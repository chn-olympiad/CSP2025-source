#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,a[N][3],d[N],t;
vector<int> ok[4];
ll ans;
int check(int x){
	if (a[x][1]>=a[x][2]&&a[x][1]>=a[x][3])
		return 1;
	else if (a[x][2]>=a[x][1]&&a[x][2]>=a[x][3])
		return 2;
	else return 3;
}
int check1(int x){
	if ((a[x][1]>=a[x][2]&&a[x][1]<=a[x][3])||(a[x][1]<=a[x][2]&&a[x][1]>=a[x][3]))
		return 1;
	else if ((a[x][2]>=a[x][1]&&a[x][2]<=a[x][3])||(a[x][2]<=a[x][1]&&a[x][2]>=a[x][3]))
		return 2;
	else return 3;
}
priority_queue<int> q;
void init(){
	ok[1].clear(),ok[2].clear(),ok[3].clear();
	while (!q.empty()) q.pop();
	ans=0;
}
int cnt[91];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while (t--){
		init();
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d%d%d",a[i]+1,a[i]+2,a[i]+3);
		for (int i=1;i<=n;i++){
			d[i]=check(i);
			ok[d[i]].push_back(i);
			ans+=a[i][d[i]];
		}
		if ((int)ok[1].size()<=n/2&&(int)ok[2].size()<=n/2&&(int)ok[3].size()<=n/2)
			{printf("%lld\n",ans);continue;}
		int p=0;
		if ((int)ok[1].size()>n/2) p=1;
		else if ((int)ok[2].size()>n/2) p=2;
		else p=3;
		for (int i : ok[p])
			q.push(a[i][check1(i)]-a[i][d[i]]);
		for (int i=1;i<=(int)ok[p].size()-n/2;i++)
			ans+=q.top(),q.pop();
		printf("%lld\n",ans);
	}
	return 0;
}
