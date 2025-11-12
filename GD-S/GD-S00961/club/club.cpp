#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

const int N=1e5+5;
int tot1,tot2,tot3;
int t,n;
bool f;
long long ans=0;
struct STU {
	int A,B,C;
}stu[N];
struct Node {
	int id,f,cnt;
	bool operator < (const Node&y) const
	{
		return y.cnt<cnt;
	}
};
priority_queue <Node> pqa,pqb,pqc;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	int a=0,b=0,c=0;
	bool f=false;
	while (t--) {
		scanf("%d",&n);
		if (n>30) f=true;
		else f=false;
		for (int i=1;i<=n;i++) {
			scanf("%d %d %d",&stu[i].A,&stu[i].B,&stu[i].C);
			if (stu[i].A>=stu[i].C && stu[i].A>=stu[i].B) {
				if (f) a=stu[i].A-stu[i].B-stu[i].C;
				else a=stu[i].A-max(stu[i].B,stu[i].C);
				pqa.push({i,stu[i].A,a});
				++tot1;
			}
			else if (stu[i].B>=stu[i].C && stu[i].B>=stu[i].A) {
				if (f) b=stu[i].B-stu[i].A-stu[i].C;
				else b=stu[i].B-max(stu[i].A,stu[i].C);
				pqb.push({i,stu[i].B,b});
				++tot2;
			}
			else if (stu[i].C>=stu[i].B && stu[i].C>=stu[i].A) {
				if (f) c=stu[i].C-stu[i].B-stu[i].A;
				else c=stu[i].C-max(stu[i].A,stu[i].B);
				pqc.push({i,stu[i].C,c});
				++tot3;
			}
		} 
		while (!pqa.empty() && tot1>n/2 && tot2<=n/2 && tot3<=n/2) {
			a=pqa.top().id;
			pqa.pop();
			tot1--;
			if (stu[a].B>=stu[a].C && tot2<n/2) {
				tot2++;
				b=stu[a].B-stu[a].C;
				pqb.push({a,stu[a].B,b});
			}
			else if (stu[a].B<=stu[a].C && tot3<n/2) {
				tot3++;
				c=stu[a].C-stu[a].B;
				pqc.push({a,stu[a].C,c});
			}
		}
		while (!pqb.empty() && tot1<=n/2 && tot3<=n/2 && tot2>n/2) {
			b=pqb.top().id;
			pqb.pop();
			tot2--;
			if (stu[b].A>=stu[b].C && tot1<n/2) {
				tot1++;
				a=stu[b].A-stu[b].C;
				pqa.push({b,stu[b].A,a});
			}
			else if (stu[b].A<=stu[b].C && tot3<n/2) {
				tot3++;
				c=stu[b].C-stu[b].A;
				pqc.push({b,stu[b].C,c});
			}
		}
		while (!pqc.empty() && tot3>n/2 && tot2<=n/2 && tot1<=n/2) {
			c=pqc.top().id;
			pqc.pop();
			tot3--;
			if (stu[c].B>=stu[c].A && tot2<n/2) {
				tot2++;
				b=stu[c].B-stu[c].A;
				pqb.push({c,stu[c].B,b});
			}
			else if (stu[c].B<=stu[c].A && tot1<n/2) {
				tot1++;
				a=stu[c].A-stu[c].B;
				pqa.push({c,stu[c].A,a});
			}
		}
		while (!pqa.empty()) {
			ans+=(1LL)*pqa.top().f;
			pqa.pop();
		}
		while (!pqb.empty()) {
			ans+=(1LL)*pqb.top().f;
			pqb.pop();
		}
		while (!pqc.empty()) {
			ans+=(1LL)*pqc.top().f;
			pqc.pop();
		}
		printf("%lld\n",ans);
		ans=0; tot1=0; tot2=0; tot3=0;
		for (int i=1;i<=n;i++) {
			stu[i].A=0;
			stu[i].B=0;
			stu[i].C=0; 
		}
	}
	return 0;
}
