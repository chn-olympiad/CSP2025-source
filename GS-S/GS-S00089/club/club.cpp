#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t;
bool cmp(int a,int b){
	if(a>b){
		return true;
	}return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int n,ans=0;
		int a[maxn],b[maxn],c[maxn];
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",a+i,b+i,c+i);
		}
		sort(b+1,b+n+1,cmp);
		for(int i=1;i<=n>>1;++i){
			ans+=b[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
