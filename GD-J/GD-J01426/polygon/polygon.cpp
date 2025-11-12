#include<bits/stdc++.h>
using namespace std;
const int MAXN=5010,MOD=998244353;
int a[MAXN];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<3) {
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	long long ma=(1<<n)-1;
	long long ans=0;
	for(long long sub_set=7; sub_set<=ma; sub_set++) {
		int cnt=0;
		long long sum=0,tmp=0;
		for(int now=1; now<=n; now++) {
			if(sub_set&(1<<(n-now))) {
				cnt++;
				sum+=a[now];
				tmp=now;
			}
		}
		if(cnt>=3&&sum>2*a[tmp]) {
			ans++;
			ans%=MOD;
			cout<<sub_set<<endl;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}

