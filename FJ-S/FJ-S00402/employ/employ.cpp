#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[505],flag,ans=1,cnt;
string s;

int jc(int x){
	int sum=1;
	for(int i=x;i>=2;i--) sum*=x,sum%=mod;
	return sum;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int i=1;
	for(i;i<=n;i++){
		if(a[i]>cnt) ans++,cnt++;
		if(a[i]==cnt){
			for(int j=i+1;j<=n;j++){
				if(a[j]==a[i]) flag=j;
			}
			ans=jc(ans);
			ans*=flag-i;
			ans%=mod;
			i=flag;
		}
	}
	cout << ans;
	return 0;
}
