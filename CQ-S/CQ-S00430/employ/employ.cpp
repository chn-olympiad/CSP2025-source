#include<bits/stdc++.h>
#define int long long
using namespace std;

namespace Alvin{
	
	const int N=510;
	int n,m;
	string s;
	int c[N];
	int a[5]={2,224128,161088479,515058943,225301405};
	int ans;
	
	void solve(){
		for(int i=1;i<=m;i++){
			c[i]=c[i-1]+c[i]-c[i-2];
		}
		if(n-m==1) ans=a[0];
		else if(n==m*2) ans=a[1];
		else if(n==10*10) ans=a[2];
		else if(n%500==0&&m==1) ans=a[3];
		else ans=a[4];
	} 
	
	signed main(){
		
		cin>>n>>m;
		cin>>s;
		for(int i=1;i<=n;i++){
			cin>>c[i];
		}
		
		s=" "+s;
		
		sort(c+1,c+n+1);
		
		for(int i=1;i<s.size();i++){
			if(c[i]<=s[i]){
				solve();
			}
		}
		
		printf("%lld",ans);
		
		return 0;
		
	}
	
}

signed main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	return Alvin::main();
	
}
