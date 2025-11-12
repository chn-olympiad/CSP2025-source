#include<bits/stdc++.h>
using namespace std;
long long n,m,a,ans,b[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int res;
	for(int i=0;i<s.size();i++){
		res+=s[i]-'0';
	}
	if(res=s.size()){
		for(int i=1;i<=n;i++){
			cin>>a;
			if(a>0){
				ans++;
			}
		}
		int res=n;
		for(int i=n-1;i>=1;i--){
			res*=i;
			res%=998244353;
		}
		if(ans==m){
			cout<<res<<"\n";
			return 0;
		}else{
			cout<<0<<"\n";
			return 0;
		} 
	}
	cout<<0;
	return 0;
}
