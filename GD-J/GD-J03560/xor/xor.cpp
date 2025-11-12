#include<bits/stdc++.h>
using namespace std;
long long n,k,t,a[510000],ans,l,r;
bool b[5959810];
struct node{
	long long x,y;
}f[5919810];
int cmp(node a,node b){
	if(a.x==b.x) return a.y-a.x<b.y-b.x;
	return a.x<b.x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=i;j<=n;j++){
			x=x | a[j];
			if(x==k) {
				f[++t]={i,j};
			}
		}
	}
	sort(f+1,f+1+t,cmp);
	for(int i=1;i<=t;i++){
		if(f[i].x<=r) continue;
		r=f[i].y;
		ans++;
	}
	cout<<ans;
	return 0;
}
