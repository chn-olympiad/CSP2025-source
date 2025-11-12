#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x,y;
}c[500010];
int n,k,a[500010],sum[500010],f[500010];
bool cmp(Node x,Node y){
	if(x.x==y.x) return x.y<y.y;
	else return x.x<y.x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) sum[i]=a[i];
		else sum[i]=sum[i-1]^a[i];
	}
	int tmp=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(((sum[i])^(sum[j-1]))==k){
				c[++tmp].x=j;
				c[tmp].y=i;
			}
		}
	}
	sort(c+1,c+1+tmp,cmp);
	for(int i=1;i<=tmp;i++) f[i]=1;
	for(int i=1;i<=tmp;i++){
		for(int j=1;j<=i;j++){
			if(c[j].y<c[i].x) f[i]=max(f[i],f[j]+1);
		}
	}
	int ans=0;
	for(int i=1;i<=tmp;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans<<endl;
	return 0;
}
