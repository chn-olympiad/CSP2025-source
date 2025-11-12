#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n;
int a[N],b[N],c[N];
int ma;
void dfs(int cnt,int h,int ta,int tb,int tc){
	if(h==n){
		ma=max(ma,cnt);
	}
	h++;
	if(ta*2<n)dfs(cnt+a[h],h,ta+1,tb,tc);
	if(tb*2<n)dfs(cnt+b[h],h,ta,tb+1,tc);
	if(tc*2<n)dfs(cnt+c[h],h,ta,tb,tc+1);
} 
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d",&n);
		ma=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		}
		if(n>30){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i*2<=n;i++){
				ma+=a[i];
			}
			cout<<ma;
			continue;
		}
		dfs(0,0,0,0,0);
		cout<<ma<<'\n';
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
