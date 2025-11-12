#include <bits/stdc++.h>
using namespace std;
int s[510],c[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	char ch;
	int cnt=0;
	for (int i=1;i<=n;i++){
		cin>>ch;
		s[i]=ch-'0';
		cnt+=s[i];
	}
	if (cnt<m){
		printf("0\n");
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if (!c[i]){
			printf("0\n");
			return 0;
		}
	}
	if (cnt==n){
		long long pi=1;
		for (int i=2;i<=n;i++){
			pi*=i;
		}
		printf("%lld\n",pi);
	}
	else{
		printf("0\n");
	}
	return 0;
}
