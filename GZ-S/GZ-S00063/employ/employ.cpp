//GZ-S00063 北京师范大学贵阳附属中学 刘祚诚 
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,MOD=998244353;
int c[N];
int n,m;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int cnts1=0;
	cin>>s;
	for(int i=0;i<s.size();i++){	
		if(s[i]=='1')cnts1++;
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	if(cnts1==n){
		int ans=1;
		for(int i=n;i>=1;i--){
			ans*=i;
			ans%=MOD;
		}
		cout<<ans<<endl;		
	}
	if(m==1){
		if(cnts1==0)cout<<0<<endl;
		else {
			int ans=1;
			for(int i=n;i>=cnts1;i--){
				ans*=i;
				ans%=MOD;
			}
			cout<<ans<<endl;
		}
		return 0;
	}else if(m==n){
		if(cnts1==n)cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}else{
		int ans=1;
		for(int i=n;i>=cnts1;i--){
			ans*=i;
			ans%=MOD;
		}
		cout<<ans<<endl;	
	}
	return 0;
}

