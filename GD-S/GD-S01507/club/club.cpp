#include <bits/stdc++.h>
using namespace std;
long long n,ans,f[100005];
struct my{
	long long v1,v2,v3;
	long long b;
}a[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin >>t;
	while(t--){
		ans =0;
		long long n;cin >>n;
		for(int i=1;i<=n;i++) cin >>a[i].v1>>a[i].v2>>a[i].v3;
		for(int i=1;i<=n;i++) ans+=max(a[i].v1,max(a[i].v2,a[i].v3));
		cout <<ans;
	}
	
	return 0;
}
