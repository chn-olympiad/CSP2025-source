#include<bits/stdc++.h>
using namespace std;
long long n,ans=1;
void jc(long long n){
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	jc(n);                
	cout<<ans;
	return 0;
}
