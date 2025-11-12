#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int b[500005];
/*
int ans;
bool check(int mid) {
	int cnt=0;
	for(int i=1;i<=mid;i++) {
		
	}
}
int find(int l,int r){
		
	while(l<r) {
		int mid=l+r>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
*/
struct node{
	int l,r;
}cnt[200005];
int tot;
bool cmp(node a,node b){
	if(a.r==b.r) return a.l<b.l;
	else return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		b[i]=b[i-1]^a[i];
	}
//	for(int i=1;i<=n;i++) cout<<b[i]<<" ";
	//cout<<endl;
	//cout<<find(0,n);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=i;j++) {
			if((b[i]^b[j-1])==k) cnt[++tot]={j,i};
		}
	}
	sort(cnt+1,cnt+1+tot,cmp);
//	cout<<tot<<endl;
	int tmpl=0,tmpr=0,ans=0;
	for(int i=1;i<=tot;i++) {
//		cout<<cnt[i].l<<" "<<cnt[i].r<<endl;
		if(cnt[i].l>tmpr) {ans++,tmpl=cnt[i].l,tmpr=cnt[i].r;}
	}
	cout<<ans;
}
