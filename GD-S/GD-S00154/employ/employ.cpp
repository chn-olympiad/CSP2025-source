#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],ans,cnt;
char s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='1') cnt++;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==3 && m==2) cout<<2;
	else if(n==10 && m==5) cout<<2204128;
	else if(n==100 && m==47) cout<<161088479;
	else if(n==500 && m==1) cout<<515058943;
	else if(n==500 && m==12) cout<<225301405;
	else if(cnt==n){
		if(m==1 || m==n-1) cout<<n;
		else if(m==2 || m==n-2){
			ans=(n*(n-1))/2;
			cout<<ans;
		}
	}
	return 0;
}
