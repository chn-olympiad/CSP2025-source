#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}d[500005];
int n,k,a[500005],s[500005],cnt,x,y;
bool cmp(node a,node b){
	if(a.r==b.r){
		return a.l>b.l;
	}
	return a.r<b.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();cout.tie();
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((s[j]^s[i-1])==k){
				d[++cnt].l=i;
				d[cnt].r=j;
			}
		}
	}
	sort(d+1,d+cnt+1,cmp);
	if(cnt){
		x=1;y=d[1].r;
		for(int i=2;i<=cnt;i++){
			if(d[i].l>y){
				x++;
				y=d[i].r;
			}
		}
	}
	cout<<x;
	return 0;
}
