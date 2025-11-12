//GZ-S00072 贵阳中天中学 卓然
#include<bits/stdc++.h>
using namespace std;
int T;
int a[100005];
int b[100005];
int c[100005];
int n;
int ans,ans1,ans2;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i]>>b[i]>>c[i];
			//ans+=max(a[i],max(b[i],c[i]));
		}
		if(n==2) {
			ans1+=max(max(a[1],b[1]),c[1]);
			if(ans1==a[1])ans1+=max(b[2],c[2]);
			else if(ans1==b[1])ans1+=max(a[2],c[2]);
			else if(ans1==c[1])ans1+=max(a[2],b[2]);

			ans2+=max(max(a[2],b[2]),c[2]);
			if(ans2==a[2])ans1+=max(b[1],c[1]);
			else if(ans2==b[2])ans2+=max(a[1],c[1]);
			else if(ans2==c[2])ans2+=max(a[1],b[1]);

			ans=max(ans1,ans2);
		} else {
			sort(a+1,a+n+1,cmp);
			for(int i=1; i<=n/2; i++) {
				ans+=a[i];
			}
		}
		cout<<ans;
	}
	return 0;
}
