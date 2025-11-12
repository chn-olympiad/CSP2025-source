//GZ-S00010 付滨诚 贵阳市南明区双龙华麟学校
#include<bits/stdc++.h>
using namespace std;
long long m,n,c[505],ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]!=1){
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=n;i++) ans=(ans*i)%998244353;
	cout<<ans;
	return 0;
} 
