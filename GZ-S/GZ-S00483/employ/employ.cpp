//GZ-S00483 贵阳市南明区华麟学校 陈锦江
#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch=='-'){
		f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i%mod;
	}
	cout<<ans;
	return 0;
}

