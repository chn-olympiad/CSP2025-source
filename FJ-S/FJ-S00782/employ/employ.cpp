#include <bits/stdc++.h>
using namespace std;
int n,m,a[520];
string s,d;
long long cnt;
int main(){
	freopen ("employ.in","r",stdin);  
	freopen ("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		cnt=1;
		for(int i=2;i<=n;i++){
			if(a[i]!=0)cnt*=a[i];
			else cnt++;
		}
		printf("%lld",cnt%998244353);
	}
	return 0;
}
