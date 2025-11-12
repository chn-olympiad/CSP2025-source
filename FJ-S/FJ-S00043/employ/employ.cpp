#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505];
char s[505];
bool flag=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out ","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]!='1')flag=0;
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+n+1);
	if(flag){
		int val=1,cnt=n;
		for(int i=1;i<=n;i++)if(c[i]==0)cnt--;
		for(int i=2;i<=n;i++){
			val=val*i%998244353;
		}
		cout<<val;
	}
	return 0;
}

