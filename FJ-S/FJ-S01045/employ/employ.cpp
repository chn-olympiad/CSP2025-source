#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[505],c[505];
string s; 
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for (int i = 1;i <= n;i++) {cin >> c[i];a[i] = i;}
	do{
		int cnt = 0,pass = 0,flag = 0;
		for (int i = 1;i <= n;i++){ //a[i]
			if (cnt >= c[a[i]] || s[i-1]=='0') cnt++;
			else pass++;
			if (pass >= m){
				flag=1;
				break;
			}
		}if(flag) ans=(ans+1)%998224353;
	}while(next_permutation(a+1,a+n+1));
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
