#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,t;
long long ans;
int a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			a[i]=max(x,max(y,z));
		}
		sort(a+1,a+n+1);
		for(int i=n;i>n/2;i--){
			ans+=a[i];
		}
		printf("%lld\n",ans);
	}	
	return 0;
}
