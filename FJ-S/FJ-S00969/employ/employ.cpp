#include<bits/stdc++.h>
using namespace std;
char c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	int cnt=0;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf(" %c",&c[i]);
		if(c[i]=='1'){
			cnt++;
		}
	}
	int ans=1;
	for(int i=1; i<=cnt; i++){
		ans=(ans*i)%998244353;
	}
	cout<<ans;
	return 0;
} 
