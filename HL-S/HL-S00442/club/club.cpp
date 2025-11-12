#include<bits/stdc++.h>
using namespace std;
int t;
bool cmp(int a,int b){
	return a>=b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int n;scanf("%d",&n);
		int a[100010],b[100010],c[100010];
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i],&b[i],&c[i]);
		}
		sort(a+1,a+n+1,cmp);
		long long ans=0;
		for(int i=1;i<=n/2;i++)ans+=a[i];
		printf("%lld\n",ans);
	}
	return 0;
}
//这是一个仅有几分的代码 是属于HDL的光荣
//我好累
//我好累
//我好累

