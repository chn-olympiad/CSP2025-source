#include <bits/stdc++.h>
using namespace std;
struct aaa{
	int a,b,c,d;
};
int n;
int ans;
void bbb(int x,int s,int z[],aaa a[]){
	if(x==n){
		ans=max(ans,s);
		return;
	}
	if(z[1]<n/2){
		z[1]++;
		bbb(x+1,s+a[x+1].a,z,a);
		z[1]--;
	}
	if(z[2]<n/2){
		z[2]++;
		bbb(x+1,s+a[x+1].b,z,a);
		z[2]--;
	}
	if(z[3]<n/2){
		z[3]++;
		bbb(x+1,s+a[x+1].c,z,a);
		z[3]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		aaa a[n+10]{};
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		}
		int z[10]{};
		if(n>10){
			int b[n+10]{};
			for(int i=1;i<=n;i++){
				b[i]=a[i].a;
			}
			sort(b+1,b+n+1);
			for(int i=1;i<=n/2;i++){
				ans+=b[i];
			}
			printf("%d\n",ans);
			continue;
		}
		bbb(0,0,z,a);
		printf("%d\n",ans);
	}
	return 0;
} 
