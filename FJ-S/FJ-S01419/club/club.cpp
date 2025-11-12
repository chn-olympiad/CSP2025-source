#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N][4],T,cnt,b[4],flag=1;
bool bj1,bj2,bj3;
struct node{
	int v,w;
	friend bool operator <(const node &a,const node &b){
		return a.w>b.w;
	}
};
priority_queue<node>q1,q2,q3;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		
		int cnt1=0,cnt2=0,cnt3=0,pd=n/2;
		long long sum=0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				scanf("%d",&a[i][j]);
			}
			if(a[i][2]||a[i][3]!=0) flag=0;
		}
		if(flag){
			for(int i=1;i<=n;i++){
				q1.push({0,a[i][1]});
			}
			for(int i=1;i<=n;i++){
				if(i>pd) sum+=q1.top().w;
				q1.pop();
			}
			printf("%lld\n",sum);
			continue;
		}
		for(int i=1; i<=n; i++) {
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]) {
				if(cnt1<pd) {
					cnt1++;
					q1.push({0,a[i][1]});
					sum+=a[i][1];
				}
				else if(a[i][1]>q1.top().w){
					sum-=q1.top().w;
					sum+=a[i][1];
					q1.pop();
					q1.push({0,a[i][1]});
				}
				else if(a[i][2]>a[i][3]&&cnt2<pd){
					cnt2++;
					sum+=a[i][2];
					q2.push({0,a[i][2]});
				}
				else if(cnt3<pd){
					cnt3++;
					sum+=a[i][3];
					q3.push({0,a[i][3]});
				}
			}
			if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]) {
				if(cnt2<pd){
					cnt2++;
					q2.push({0,a[i][2]});
					sum+=a[i][2];
				}
				else if(a[i][2]>q2.top().w){
					sum-=q2.top().w;
					sum+=a[i][2];
					q2.pop();
					q2.push({0,a[i][2]});
				}
				else if(a[i][1]>a[i][3]&&cnt1<pd){
					cnt1++;
					sum+=a[i][1];
					q1.push({0,a[i][1]});
				}
				else if(cnt3<pd){
					cnt3++;
					sum+=a[i][3];
					q3.push({0,a[i][3]});
				}
			}
			if(a[i][3]>a[i][1]&&a[i][3]>a[i][2]) {
				if(cnt3<pd){
					cnt3++;
					q3.push({0,a[i][3]});
					sum+=a[i][3];
				}
				else if(a[i][3]>q3.top().w){
					sum-=q3.top().w;
					sum+=a[i][3];
					q3.pop();
					q3.push({0,a[i][3]});
				}
				else if(a[i][2]>a[i][1]&&cnt2<pd){
					cnt2++;
					sum+=a[i][2];
					q2.push({0,a[i][2]});
				}
				else if(cnt1<pd){
					cnt1++;
					sum+=a[i][1];
					q1.push({0,a[i][1]});
				}
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
