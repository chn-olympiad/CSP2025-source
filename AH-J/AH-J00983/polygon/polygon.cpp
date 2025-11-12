#include <bits/stdc++.h>
using namespace std;
int n;
int a[114514];
int mx;
int ans;
int mix;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==3){
		if(a[1]+a[2]>a[3] && a[1]+a[3]>a[2] && a[2]+a[3]>a[1])cout<<1;
		else cout<<0;
	}
	if(n==4){
		for(int i=1;i<n;i++)mx=max(a[i],a[i+1]);
		if(a[1]+a[2]>a[3] && a[1]+a[3]>a[2] && a[2]+a[3]>a[1])ans++;
		if(a[1]+a[2]>a[4] && a[1]+a[4]>a[2] && a[2]+a[4]>a[1])ans++;
		if(a[1]+a[4]>a[3] && a[1]+a[3]>a[4] && a[4]+a[3]>a[1])ans++;
		if(a[4]+a[2]>a[3] && a[4]+a[3]>a[2] && a[2]+a[3]>a[4])ans++;
		if(a[1]+a[2]+a[3]+a[4]>2*mx)ans++;
		cout<<ans;
	}
	if(n==5){
		for(int i=1;i<n;i++)mx=max(a[i],a[i+1]);
		for(int i=1;i<n-1;i++)mix=max(a[i],a[i+1]);
		if(a[1]+a[2]>a[3] && a[1]+a[3]>a[2] && a[2]+a[3]>a[1])ans++;
		if(a[1]+a[2]>a[4] && a[1]+a[4]>a[2] && a[2]+a[4]>a[1])ans++;
		if(a[1]+a[4]>a[3] && a[1]+a[3]>a[4] && a[4]+a[3]>a[1])ans++;
		if(a[4]+a[2]>a[3] && a[4]+a[3]>a[2] && a[2]+a[3]>a[4])ans++;
		if(a[1]+a[2]>a[5] && a[1]+a[5]>a[2] && a[2]+a[5]>a[1])ans++;
		if(a[1]+a[3]>a[5] && a[1]+a[5]>a[3] && a[3]+a[5]>a[1])ans++;
		if(a[1]+a[4]>a[5] && a[1]+a[5]>a[4] && a[4]+a[5]>a[1])ans++;
		if(a[3]+a[2]>a[5] && a[3]+a[5]>a[2] && a[2]+a[5]>a[3])ans++;
		if(a[4]+a[2]>a[5] && a[4]+a[5]>a[2] && a[2]+a[5]>a[4])ans++;
		if(a[4]+a[3]>a[5] && a[3]+a[5]>a[4] && a[4]+a[5]>a[3])ans++;
		if(a[1]+a[2]+a[3]+a[4]>2*mix)ans++;
		if(a[1]+a[2]+a[3]+a[5]>2*max(max(a[1],a[2]),max(a[3],a[5])))ans++;
		if(a[1]+a[2]+a[5]+a[4]>2*max(max(a[1],a[2]),max(a[4],a[5])))ans++;
		if(a[5]+a[2]+a[3]+a[4]>2*max(max(a[4],a[2]),max(a[3],a[5])))ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>2*mx)ans++;
		cout<<ans;
	}
	return 0;
}
