#include<bits/stdc++.h>
using namespace std;
long long t;
long long n;
struct stu{
	long long a,b,c;
	long long p[5];
	friend bool operator <(stu x,stu y) {
		return (x.p[3] - x.p[2]) > (y.p[3] - y.p[2]);
	}
}node[100005];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--) {
		scanf("%lld",&n);
		long long num1 = 0,num2 = 0,num3 = 0,ans = 0;
		for(int i = 1;i <= n;i++) {
			scanf("%lld %lld %lld",&node[i].a,&node[i].b,&node[i].c);
			node[i].p[1] = node[i].a;
			node[i].p[2] = node[i].b;
			node[i].p[3] = node[i].c;
			sort(node[i].p + 1,node[i].p + 4);
		}
		sort(node + 1,node + n + 1);
		for(int i = 1;i <= n;i++) {
			if(node[i].p[3] == node[i].a) {
				if(num1 < n / 2) {
					num1++;
					ans += node[i].p[3];
				}
				else ans += node[i].p[2];
			}
			else if(node[i].p[3] == node[i].b) {
				if(num2 < n / 2) {
					num2++;
					ans += node[i].p[3];
				}
				else ans += node[i].p[2];
			}
			else {
				if(num3 < n / 2) {
					num3++;
					ans += node[i].p[3];
				}
				else ans += node[i].p[2];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

