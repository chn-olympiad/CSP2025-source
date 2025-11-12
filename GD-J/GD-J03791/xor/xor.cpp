#include<bits/stdc++.h>
using namespace std;
int n,m,k,maxa=-1;
int a[500005];
struct ac{
	int l;
	int r;
	int zhi;
}b[500005];
int cmp(ac x,ac y){
	if(x.l!=y.l){
		return x.l<y.l;
	}
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==m){
			k++;
			b[k].l=i,b[k].r=i,b[k].zhi=1;
		}
	}
	for(int i=1;i<=n;i++){
		int cnt=a[i];
		for(int j=i+1;j<=n;j++){
			cnt=cnt^a[j];
			if(cnt==m){
				k++;
				b[k].l=i,b[k].r=j,b[k].zhi=1;
			}
		}
	}
	sort(b+1,b+1+k,cmp);
	for(int i=1;i<=k;i++){
		int maxb=0;
		for(int j=1;j<i;j++){
			if(b[i].l>b[j].r){
				maxb=max(maxb,b[j].zhi);
			}
		}
		b[i].zhi+=maxb;
		maxa=max(maxa,b[i].zhi);
	}
	cout<<maxa;
	return 0;
}

