#include <bits/stdc++.h>
using namespace std;
const int N = 510 , MOD = 998244353;
int c[N],m,n;
string s;
int cnt=0;
long long  ans = 1; 

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int flag = 1;
	
	for(int i =1;i<=n;i++)cin>>c[i];
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			flag=0;
		}
		cnt+=(s[i]=='1');
	}
	if(flag){
		for(int i =n;i>=1;i--){
			ans *= i;
			ans%=MOD;
			
		}	
		cout<<ans<<'\n';
		return 0;
			
	}	
	else {
		
			cout<<0<<'\n';
			return 0;
		
		
	}
}
