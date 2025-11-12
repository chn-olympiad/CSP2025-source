#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long c[550];
string s;
long long nd[550];
struct note{
	long long id,num;
}b[550];
void solve(){
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		nd[i+1]=s[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	if(m==n){
		for(int i=1;i<=n;i++){
			if(c[i]<i-1||nd[i-1]==0){
				cout<<0;
				return ;
			}
		}
	}
	if(m==1){
		if(nd[1]==0){
			cout<<0;
			return ;
		}
		else{
			long long ji=1;
			for(int i=n;i>=1;i--){
				ji*=i;
				ji%=998244353;
			}
			cout<<ji<<'\n';
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr); 
	int T=1;
	while(T--){
		solve();
	}
	
	return 0;
}
