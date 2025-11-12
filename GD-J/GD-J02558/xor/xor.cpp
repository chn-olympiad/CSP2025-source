#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,k,a[N],sum,ans,b[N],t;
struct node{
	int l,r;
}c[N];
void oi(int x){
	for(int i=1;i<=n-x+1;i++){
		if((b[i+x-1]^b[i-1])==k){
			c[t].r=i+x-1;
			c[t].l=i;
			t++;
		}
	}
}
bool cmd(node x,node y){
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=(b[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		oi(i);
	}
	ans=t;
	cout<<ans;
	return 0;
}                                   
