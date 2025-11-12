#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],n,k;
struct node{
	int num;
	int xo;
}pre[N];
struct line{
	int l,r;
}f[N];
bool cmp(node x,node y){
	if(x.xo!=y.xo) return x.xo<y.xo;
	else return x.num<y.num;
}
bool cmp2(line x,line y){
	return x.r<y.r;
}
int find(int x,int i){
	int l=0,r=n,mid;
	while(l<r){
		mid=(l+r)/2;
		if(pre[mid].xo==x && pre[mid].num>=i) r=mid;
		else if(pre[mid].xo>x) r=mid-1;
		else l=mid+1;
	}
	if(pre[l].xo!=x || pre[l].num<i) return 0;
	else return pre[l].num;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		pre[i].xo=pre[i-1].xo^a[i];
		pre[i].num=i;
	}
	pre[0].num=0; 
	sort(pre,pre+n+1,cmp);
	int t=0;
	for(int i=0;i<=n;i++){
		int x=pre[i].xo^k;
		if(pre[i].num+1>n) continue; 
		int fd=find(x,pre[i].num+1);
		if(fd==0) continue;
		else {
			t++;
			f[t].l=pre[i].num+1;
			f[t].r=fd;
		}
	}
	sort(f+1,f+t+1,cmp2);
	int ans=0,last=-1;
	for(int i=1;i<=t;i++){
		if(f[i].l<=last) continue;
		ans++;
		last=f[i].r;
	}
	cout<<ans;
	return 0;
}