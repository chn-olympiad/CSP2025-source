#include<bits/stdc++.h>
using namespace std;
int n,m;
string s; 
int main(void){
	int a;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int ans = 0;
	for(int i = 1;i<=s.size();i++){
		ans+=s[i]-'0';
	}
	int res = 0;
	if(ans == s.size()){
		for(int i = 1;i<=n;i++){
			cin>>a;
			if(a>0){
				ans++;
			}
		}
			int res = n;
			for(int i = n-1;i>=1;i--){
				res*=i;
				res%=998244353;
			}
			if(ans == m){
				cout<<res<<endl;
				return 0;
			}
			else{
				cout<<res-1<<endl;
				return 0;
			}
		}
	return 0;
} 
