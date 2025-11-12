#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}q[int(2e6+10)];
bool cmp(node a,node b){
	if(a.r!=b.r)return a.r<b.r;
	return a.l>b.l;
}
int top;
int k;
int N[int(5e5+10)];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>N[i];
	for(int i=1;i<=n;i++){
		int x=N[i];
		if(x==k){
			q[top].l=q[top].r=i;
			top++;	
		}
		for(int j=i+1;j<=n;j++){
			x=x^N[j];
			if(x==k){
			q[top].l=i;
			q[top].r=j;
			top++;	
		}
		}
	}
	sort(q,q+top,cmp);
	int r=0,ans=0;
	for(int i=0;i<top;i++){
		if(q[i].l<=r) continue;
		ans++;
		r=q[i].r;
	}
	cout<<ans;
	return 0;
}
