#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N=5e3 + 5;
int a[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	bool sp=true;
	for(int i=1;i <= n;i++){
		cin >> a[i];
		if(a[i] != 1){
			sp=false;
		}
	}
	sort(a + 1,a + n + 1);
	if(sp == true){
		int f=1,l=1;
		for(int i=4;i <= n;i++){
			l+=((i - 1) * (i - 1) / 2);
			l--;
			l%=998244353;
			f+=l;
			f%=998244353;
		}
		cout << f;
	} else{
		if(n <= 20){
			int f=0;
			int m=pow(2,n);
			for(int i=7;i <= m - 1;i++){
				int mx=-1e9,cnt=0,s=0;
				int t=i,j=0;
				while(t > 0){
					j++;
					int p=t % 2;
					cnt+=p;
					s+=(a[j] * p);
					mx=max(mx,a[j] * p);
					t/=2;
				}
				if(cnt < 3 || s <= mx * 2){
					continue;
				}
				f++;
			}
			cout << f;
		}
	}
	return 0;
}