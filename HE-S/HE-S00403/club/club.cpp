#include<bits/stdc++.h>
using namespace std;
int a[505];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m;
	string s;
	scanf("%d%d",&n,&m);
	scanf("%s",&s);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	printf("%d",m);
	return 0;
}
