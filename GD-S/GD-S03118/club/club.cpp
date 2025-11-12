#include<bits/stdc++.h>
using namespace std;
int T,n,t[5],ans;
struct node{
	int x,d;
}a[100010];
bool cmp(node x,node y){
	return x.x>y.x;
}
void init(){
	ans=t[1]=t[2]=t[3]=0;
	return;
}
signed main(){
	//!
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club5.in","r",stdin);
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d",&n);
		for(int i=1,x=0,y=0,z=0;i<=n;i++){
			scanf("%d%d%d",&x,&y,&z);
			int mx=max(x,max(y,z));
			if(x==mx)a[i].d=1;
			else if(y==mx)a[i].d=2;
			else a[i].d=3;
			if(x<y)swap(x,y);
			if(y<z)swap(y,z);
			if(x<y)swap(x,y);//
			a[i].x=x-y,ans+=x;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(t[a[i].d]<n/2)t[a[i].d]++;
			else ans-=a[i].x;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
