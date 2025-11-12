#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],ans=1;
char s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(int i=n;i>=2;i--){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
