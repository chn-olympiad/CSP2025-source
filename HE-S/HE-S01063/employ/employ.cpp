#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,c[1010],ans;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	bool f=1;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	bool f=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			f=0;
			break;
		}
	}
	if(f){
		for(int i=m;i<=n;i++){
			if(i==1)ans+=n;
			else if(i==2)ans+=(n-1)*n/2;
			else if(i==n)ans+=1;
			else{
				for(int j=1;j<=n-i+1;j++){
					ans+=j*(n-i-j+2);
				}	
			}
		}
	}
	cout<<ans;
	return 0;
}
