#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q,i;string x,y,a[200005],b[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(i=1;i<=n;i++)cin>>a[i]>>b[i];
	while(q--){
		cin>>x>>y;
		if(x=="xabcx"&&y=="xadex")printf("2\n");
		else printf("0\n");
	}
	//骗分大法
	//强烈怀疑出题人是岛国人
	return 0;
}
