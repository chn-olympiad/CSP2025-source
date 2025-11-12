#include<bits/stdc++.h>
using namespace std;
long long n,m,c[501],cnt,ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0) cnt++;
	}
	for(int i=m;i<=cnt;i++){
		long long tmp=1;
		for(int j=m;j>=cnt-i+1;j--){
			tmp*=j;
			tmp%=998244353;
		}
		ans+=tmp;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}
