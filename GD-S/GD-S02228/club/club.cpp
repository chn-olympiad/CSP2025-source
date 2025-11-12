#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
int n;
int a[100010][5];
int sta[100010][5],top[5];
int vl[100010];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		ll ans=0;
		top[1]=top[2]=top[3]=0;
		for(int i=1;i<=n;i++){
			int v=max({a[i][1],a[i][2],a[i][3]});
			if(v==a[i][1]) sta[++top[1]][1]=i;
			else if(v==a[i][2]) sta[++top[2]][2]=i;
			else sta[++top[3]][3]=i;
			ans+=v;
		}
		for(int X=1;X<=3;X++){
			if(top[X]*2<=n) continue;
			for(int i=1;i<=top[X];i++){
				int p=sta[i][X];
				int v=a[p][X]; 
				a[p][X]=-1e8;
				vl[i]=v-max({a[p][1],a[p][2],a[p][3]});
			}
			sort(vl+1,vl+1+top[X],greater<int>());
			while(top[X]*2>n) ans-=vl[top[X]--];
			break;
		}
		printf("%lld\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
