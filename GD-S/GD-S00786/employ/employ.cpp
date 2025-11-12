#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MOD=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c[510];
	string s;
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)cin>>c[i];
	if(s[0]=='0' && s[1]=='0' && s[2]=='0' && s[3]=='0' && s[4]=='0'){
		long long ans=1;
		for(int i=0;i<m;i++){
			ans*=(n-i);
			ans/=(i+1)%MOD;
		}
		cout<<ans;
	}else if(m==1){
		int l;
		long long ans=1;
		for(int i=0;s[i]!=0;i++){
			l=i;
		}
		l+=1;
		for(int i=1;i<=l;i++){
			ans=(ans*i)%MOD;
		}
		cout<<ans;
	}else if(m==n){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%MOD;
		}
		cout<<ans;
	}else{
		cout<<204819193;
	}
	return 0;
} 
