//GZ-S00051 北师大附中 刘子逍
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n,m,cnt;
ll ans=1,d;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		char p;
		cin>>p;
		if(p=='1') ++d;
	}
	for(int i=1;i<=d;++i) ans*=i;
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


