#include<bits\stdc++.h>
using namespace std;
const int N=503;
int n,m,c[N];char s[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=n;++i)cin>>c[i];
	int len=strlen(s);bool flag=0;
	for(int i=0;i<len;++i){
		if(i!='1')flag=1;
	}
	if(flag){
		long long ans=1;
		for(int i=1;i<=n;++i){
			ans=ans*i%998244353;
		}
		cout<<ans;
	}
	return 0;
}

