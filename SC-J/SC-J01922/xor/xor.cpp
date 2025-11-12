#include<bits/stdc++.h>
using namespace std;
int a[500010];
int x[500010];
struct X{
	int l,r;
}xx[2500010];
int siz=0;
bool cmp(X a,X b){
	if(a.l!=b.l){
		return a.l<b.l;
	}else{
		return a.r<b.r;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		x[i]=x[i-1]^a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1+i;j<=n;j++){
			if((x[i]^x[j])==k){
				xx[++siz]={i+1,j};
			}
		}
	}
	sort(xx+1,xx+1+siz,cmp);
	int ans=1,t=1;
	for(int i=2;i<=siz;i++){
		if(xx[i].l>xx[t].r){
			ans++;
			t=i;
		}
	}
	cout<<ans;
	return 0;
}