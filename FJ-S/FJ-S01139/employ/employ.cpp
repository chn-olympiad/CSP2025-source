#include<cstdio>
#include<iostream>
using namespace std;
char s[505];
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans,eas=0,dif=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> s[i];
		if(s[i]=='0'){
			dif++;
		}else{
			eas++;
		}
	}
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	if(eas==n){
		ans=1;
		for(int i=n;i>=1;i--){
			ans*=i;
			ans%=998244353;
		}
	}else if(eas<m){
		ans=0;
	}else if(eas<=18){
		
	}else{
		
	}
	cout << ans;
	return 0;
}
