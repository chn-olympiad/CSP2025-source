#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],b[N];
struct node{
	int l,r;
}c[N];
bool cmp(node a,node b){
	if(a.r!=b.r) return a.r<b.r;
	else return a.l<b.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	int cnt=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if((b[r]^b[l-1])==k){
				cnt++;
				c[cnt].l=l,c[cnt].r=r;
			}
		}
	}
	sort(c+1,c+cnt+1,cmp);
	int ed=c[1].r,ans=1;
	for(int i=2;i<=cnt;i++){
		if(c[i].l>ed){
			ed=c[i].r;
			ans++;
		}
	}	
	cout<<ans;
	return 0;
}
