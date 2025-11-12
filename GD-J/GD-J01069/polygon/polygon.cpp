#include <bits/stdc++.h>
#define Mod 998244353
using namespace std;

const int N=505;
int n,ans=0;
int a[N];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	memset(a,0x3f,sizeof(a));
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if (n<=3) {
		if (a[1]+a[2]+a[3]>2*a[3]) ans=1;
		else ans=0;
	}
	else if (n<=10) {
		
		if (a[1]+a[2]+a[3]>2*a[3]) ans++;
		if (a[1]+a[2]+a[4]>2*a[4]) ans++;
		if (a[1]+a[2]+a[5]>2*a[5]) ans++;
		if (a[1]+a[2]+a[6]>2*a[6]) ans++;
		if (a[1]+a[2]+a[7]>2*a[7]) ans++;
		if (a[1]+a[2]+a[8]>2*a[8]) ans++;
		if (a[1]+a[2]+a[9]>2*a[9]) ans++;
		if (a[1]+a[2]+a[10]>2*a[10]) ans++;
		if (a[1]+a[3]+a[4]>2*a[4]) ans++;
		if (a[1]+a[3]+a[5]>2*a[5]) ans++;
		if (a[1]+a[3]+a[6]>2*a[6]) ans++;
		if (a[1]+a[3]+a[7]>2*a[7]) ans++;
		if (a[1]+a[3]+a[8]>2*a[8]) ans++;
		if (a[1]+a[3]+a[9]>2*a[9]) ans++;
		if (a[1]+a[3]+a[10]>2*a[10]) ans++;
		if (a[1]+a[4]+a[5]>2*a[5]) ans++;
		if (a[1]+a[4]+a[6]>2*a[6]) ans++;
		if (a[1]+a[4]+a[7]>2*a[7]) ans++;
		if (a[1]+a[4]+a[8]>2*a[8]) ans++;
		if (a[1]+a[4]+a[9]>2*a[9]) ans++;
		if (a[1]+a[4]+a[10]>2*a[10]) ans++;
		if (a[1]+a[5]+a[6]>2*a[6]) ans++;
		if (a[1]+a[5]+a[7]>2*a[7]) ans++;
		if (a[1]+a[5]+a[8]>2*a[8]) ans++;
		if (a[1]+a[5]+a[9]>2*a[9]) ans++;
		if (a[1]+a[5]+a[10]>2*a[10]) ans++;
		if (a[1]+a[6]+a[7]>2*a[7]) ans++;
		if (a[1]+a[6]+a[8]>2*a[8]) ans++;
		if (a[1]+a[6]+a[9]>2*a[9]) ans++;
		if (a[1]+a[6]+a[10]>2*a[10]) ans++;
		if (a[1]+a[7]+a[8]>2*a[8]) ans++;
		if (a[1]+a[7]+a[9]>2*a[9]) ans++;
		if (a[1]+a[7]+a[10]>2*a[10]) ans++;
		if (a[1]+a[8]+a[9]>2*a[9]) ans++;
		if (a[1]+a[8]+a[9]>2*a[10]) ans++;
		if (a[1]+a[9]+a[10]>2*a[10]) ans++;
		if (n<=6) {
			if (a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>2*a[6]) ans++;
			if (a[2]+a[3]+a[4]+a[5]+a[6]>2*a[6]) ans++;
			if (a[1]+a[2]+a[4]+a[5]+a[6]>2*a[6]) ans++;
			if (a[1]+a[2]+a[3]+a[5]+a[6]>2*a[6]) ans++;
			if (a[1]+a[2]+a[3]+a[4]+a[6]>2*a[6]) ans++;
			if (a[1]+a[2]+a[3]+a[4]+a[5]>2*a[5]) ans++;
			if (a[1]+a[2]+a[3]+a[5]>2*a[5]) ans++;
			if (a[1]+a[2]+a[4]+a[5]>2*a[5]) ans++;
			if (a[1]+a[3]+a[4]+a[5]>2*a[5]) ans++;
			if (a[2]+a[3]+a[4]+a[5]>2*a[5]) ans++;
			if (a[3]+a[4]+a[5]>2*a[5]) ans++;
			if (a[1]+a[4]+a[5]>2*a[5]) ans++;
			if (a[1]+a[2]+a[3]+a[5]>2*a[5]) ans++;
		}
	}
	else ans=2330;
	cout<<ans%Mod;
	return 0;
}
