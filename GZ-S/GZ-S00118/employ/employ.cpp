//GZ-S00118 安顺市第一高级中学 商裕如
#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(false),cin.tie(0)

using namespace std;
const int N=105;
#define M 998244353
//shi nian oi yichang kong ...... 
string ss;
int c[N];
int main() {
	//freopen("enploy.in","r",stdin);
	//freopen("employ.out","w",stdout);
	ios;
	int n,m;cin>>n>>m;
	cin >> ss;
	
	int len=ss.length();
	
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int sum=0;
	for(int i=1;i<=len;i++){
		if(ss[i]=='0'){
			for(int j=1;j<=n;j++){
				c[j]--;
				
			}
		}
		else sum++;
	}
	/*for(int j=1;j<=n;j++){
		if(!c[j])sum--;
	}*/
	if(sum>=m)cout<<m%M<<'\n';
	else cout << sum%M <<'\n';
	
	return 0;
}
