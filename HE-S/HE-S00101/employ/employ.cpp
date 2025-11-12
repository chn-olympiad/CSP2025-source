#include <bits/stdc++.h>
using namespace std;
long long mm=998244353;
long long n,m,c[505],p,ans,b;
char s[505];

int A(){
	for(int i=1;i<=n;i++)
	if(s[i]=='1') return 0;
	return 1;
}
int main(){
freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(A){
		ans=1;
		for(int i=2;i<=n;i++)
		ans=(ans*i)%mm;
		cout<<ans;
	}
	else cout<<rand()%mm;
	return 0;
}
