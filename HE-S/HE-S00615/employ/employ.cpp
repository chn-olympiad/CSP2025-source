#include<bits/stdc++.h>
using namespace std;
string t;
long long n,m,s[505],ans,c[505],ss;
bool a=1,b=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>t;
	for(int i=0;i<n;i++){
		s[i+1]=t[i]-'0';
		if(s[i+1]!=1){
			a=0;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		if(c[i]==0){
			ss++;
		}
	}
	if(n-ss<m){
		printf("0");
		return 0;
	}
	if(a){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%998244353;
		}
		printf("%lld",ans);
		return 0;
	}
	printf("0");
	return 0;
}  
