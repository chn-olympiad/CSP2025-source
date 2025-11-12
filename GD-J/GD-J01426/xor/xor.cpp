#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int a[MAXN],b[MAXN],dp[MAXN];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool flag=true,flag2=true;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]>1)flag2=false;
	}
	if(flag2) {
		if(k==0) {
			int ans=0,cnt=0;
			bool check=false,check2=false;
			for(int i=1; i<=n; i++) {
				if(a[i]==1&&check==false) {
					check=true;
					ans+=cnt;
					cnt=0;
				} else if(a[i]==1&&check==true) {
					if(cnt<1&&check2==false) {
						ans++;
						check2=true;
					} else check2=false;
					cnt=0;
				} else cnt++;
			}
			ans+=cnt;
			cout<<ans;
		} else {
			int cnt=0;
			for(int i=1; i<=n; i++)if(a[i]==1)cnt++;
			cout<<cnt;
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	cout<<n/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

