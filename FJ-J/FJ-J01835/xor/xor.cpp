#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],s[500001],b=1,ans=1,flag;
struct node{
	int l,r;
}c[1000001];
bool cmp(node x,node y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]^s[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(s[i-1]^s[j]==k){
				c[b].l=i-1;
				c[b].r=j;
				b++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			c[b].l=i;
			c[b].r=i;
			b++;
		}
	}
	b--;
	sort(c+1,c+b+1,cmp);
	flag=c[1].r;
	for(int i=2;i<=b;i++){
		if(c[i].l>flag){
			flag=c[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
