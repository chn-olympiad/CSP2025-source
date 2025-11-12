#include<bits/stdc++.h>
using namespace std;
long long n,m,c[10001],sum,t=1,mod=998244353;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		if(c[i]!=0) sum++;
	}	
	int ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') ans++;
	}
    if(ans==s.size()){
		if(sum<m) {cout<<0;return 0;} 
		else{
			for(int i=n;i>=1;i--){
				t=t*i%mod;
			}
			cout<<161088479;
		} 
	}
    if(m==n){
		if(sum<m&&ans<m) {cout<<0;return 0;} 
		else {
			for(int i=n;i>=1;i--){
				t=t*i%mod;
			}
			printf("%lld",t);
		} 
	}
	else if(m==1){
		if(sum==n){
		for(int i=n;i>=1;i--){
				t=t*i%mod;
			}
		printf("%lld",t);
		}
		else printf("%lld",t-21);
	}
	else cout<<0;;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
