#include<bits/stdc++.h>
using namespace std;
struct poe{
	int t1,t2,t3;
};
const int N = 1e5+5;
int T,n;
poe a[N];
int c1,c2,c3;
int ans = -1;
void init(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d%d%d",&a[i].t1,&a[i].t2,&a[i].t3);
	}
	c1 = 0,c2 = 0,c3 = 0;
}
void work(int id,int res){
	if(id>n){
		ans=max(res,ans);
		return ;
	}
	int t1,t2,t3;
	if(c1!=n/2){
		c1++;
		work(id+1,res+a[id].t1);
		c1--;
	}
	if(c2!=n/2){
		c2++;
		work(id+1,res+a[id].t2);
		c2--;
	}
	if(c3!=n/2){
		c3++;
		work(id+1,res+a[id].t3);
		c3--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		init();
		work(1,-1);
		printf("%d\n",ans);
	}
	return 0;
}
