#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,a[501] = {0},s[501] = {0};
const int mod = 998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
//	cout<<n<<" "<<m<<endl;
	for(int i = 1;i<=n;i++){
		char t;
		cin>>t;
		s[i] = t-'0';
	}
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=18){
		int ans = 0;
		int p[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
//		cout<<n<<endl;
//		for(int i = 1;i<=n;i++){
//			cout<<a[i]<<" ";
//		}
//		cout<<endl;
//		for(int i = 1;i<=n;i++){
//			cout<<s[i]<<" ";
//		}
//		cout<<endl;
		do{
			int cnt = 0,num = 0;
			for(int i = 1;i<=n;i++){
//				cout<<a[p[i]]<<" ";
				if(num>=a[p[i]]){
					num++;continue;
				}
				if(s[i]==0){
					num++;
				}else{
					cnt++;
				}
			}
//			cout<<endl;
			ans+=(cnt>=m);
			if(ans==mod)ans = 0;
		}while(next_permutation(p+1,p+1+n));
		cout<<ans<<endl;
	}
	return 0;
}
/*
100+[48,100]+50+8
*/
