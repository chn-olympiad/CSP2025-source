#include<bits/stdc++.h>
using namespace std;
unsigned long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=m;i++){
		ans*=i;
	}
	printf("lld",ans);
	return 0;
}
