#include<bits/stdc++.h>
# define Maxn 100005
using namespace std;
int T,n,x,y,z,cnt1,cnt2,cnt3,ans;
priority_queue<int> q1,q2,q3;
void clear() {
	cnt1=cnt2=cnt3=ans=0;
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	while(!q3.empty()) q3.pop();
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			scanf("%d%d%d",&x,&y,&z);
			int v=max(x,max(y,z));
			ans+=v;
			if(x==v) cnt1++,q1.push(max(y,z)-x);
			else if(y==v) cnt2++,q2.push(max(x,z)-y);
			else if(z==v) cnt3++,q3.push(max(x,y)-z);
		}
		if(cnt1>n/2) {
			while(cnt1>n/2) {
				ans+=q1.top();
				q1.pop(),cnt1--;
			}
		}
		if(cnt2>n/2) {
			while(cnt2>n/2) {
				ans+=q2.top();
				q2.pop(),cnt2--;
			}
		}
		if(cnt3>n/2) {
			while(cnt3>n/2) {
				ans+=q3.top();
				q3.pop(),cnt3--;
			}
		}printf("%d\n",ans),clear();
	}
	return 0;
}
