#include<bits/stdc++.h>
using namespace std;
int t,n,maxn=-1;
struct Stu{
	int x,y,z;
}a[100001];
void d(int m,int s,int sx,int sy,int sz){
	if(sx>n/2||sy>n/2||sz>n/2) return;
	if(m==n){
		if(sx>n/2||sy>n/2||sz>n/2) return;
		maxn=max(maxn,s);
		return;
	}
	d(m+1,s+a[m+1].x,sx+1,sy,sz);
	d(m+1,s+a[m+1].y,sx,sy+1,sz);
	d(m+1,s+a[m+1].z,sx,sy,sz+1);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		maxn=-1;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
		d(0,0,0,0,0);
		cout<<maxn<<'\n';
	}
} 
