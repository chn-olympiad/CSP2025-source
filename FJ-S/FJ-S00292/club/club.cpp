#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int T,n,mmax[N],cmax[N];
struct node{
	int v,id; 
	bool operator < (const node & x)const{
		return v < x.v;
	}
}d[N]; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int cnt[10] = {},ans = 0;
		scanf("%d",&n);
		for(int i = 1;i<=n;i++){
			node a[10];
			scanf("%d%d%d",&a[0].v,&a[1].v,&a[2].v);
			a[0].id = 1,a[1].id = 2,a[2].id = 3;
			sort(a,a+3);
			cnt[a[2].id]++;
			mmax[i] = a[2].v;
			cmax[i] = a[1].v;
			ans+=mmax[i];
//			printf("%d\n",mmax[i]);
			d[i].v = mmax[i]-cmax[i];
			d[i].id = a[2].id;
		}
//		printf("%d\n",ans);
		int t = n/2;
		if(cnt[1] > t || cnt[2] > t || cnt[3] > t){
			t = max({cnt[1],cnt[2],cnt[3]});
			int ti;
			if(cnt[1] == t)ti = 1;
			else if(cnt[2] == t)ti = 2;
			else ti = 3;
			t-=n/2;
			sort(d+1,d+n+1);
			for(int i = 1,j = 0;j<t&&i<=n;i++){
				if(d[i].id == ti){
					ans-=d[i].v;
					j++;
				}
				
			}
		}
		printf("%d\n",ans);
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
