#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct opp{
	int h[4];
}a[N];
int n,t,s[4],f[N],e;long long z;
bool cmp(opp x,opp y){
	return x.h[0]>y.h[0];
}
bool check(){
	if(s[1]==n/2)e=1;
	if(s[2]==n/2)e=2;
	if(s[3]==n/2)e=3;
	if(e)return true;
	return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		z=0;
		memset(s,0,sizeof(s));
		memset(f,0,sizeof(f));
		e=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].h[1],&a[i].h[2],&a[i].h[3]);
			a[i].h[0]=max(a[i].h[1],max(a[i].h[2],a[i].h[3]));
			int d=min(a[i].h[1],min(a[i].h[2],a[i].h[3]));
			d=a[i].h[1]+a[i].h[2]+a[i].h[3]-d-a[i].h[0];
			z+=d;
			a[i].h[1]-=d;a[i].h[2]-=d;a[i].h[3]-=d;
			a[i].h[0]=max(a[i].h[1],max(a[i].h[2],a[i].h[3]));
		}
		sort(a+1,a+n+1,cmp);
		int i;
		for(i=1;i<=n;i++){
			if(f[i])continue;
			if(check())break;
			opp w=a[i];
			z+=w.h[0];
			for(int j=1;j<=3;j++){
				if(w.h[j]==w.h[0]){
					s[j]++;
					break;
				}
			}
		}
		for(;i<=n;i++){
			if(f[i])continue;
			if(e==1){
				z+=max(a[i].h[2],a[i].h[3]);
			}
			if(e==2){
				z+=max(a[i].h[1],a[i].h[3]);
			}
			if(e==3){
				z+=max(a[i].h[2],a[i].h[1]);
			}
		}
		printf("%d\n",z);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}