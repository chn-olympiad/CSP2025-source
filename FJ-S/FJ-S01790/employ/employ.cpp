#include<bits/stdc++.h> 
using namespace std;
int n,m;
char s[505];
int c[505];
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=n;i>n-m;i--){
		ans*=i;
		ans%=998244353;
	} 
	cout<<ans;
	return 0;
}
