#include<bits/stdc++.h>
using namespace std;
int a[505];
long long p[505];
unsigned long long ans=1;
const int MOD=998244353;
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	int count=0;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]!=0) count++;
	}
	for(int i=count;i>=1;i--){
		ans=(ans*i)%MOD;
	}
	cout<<ans;
	return 0;
}
