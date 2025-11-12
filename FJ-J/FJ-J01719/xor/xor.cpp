#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[10001];
struct aa{
	int l,r,bg;
}b[100001];
bool cmp(aa x,aa y){
	if(x.l==y.l)return (x.r-x.l+1)<(y.r-y.l+1);
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	int jj=1;
	int l=1,r=1;
	while(l<=r&&r<=n){
		if(l==1&&r==1)ans=a[1];
		if(ans==k){
			b[jj].l=l;
			b[jj].r=r;
			jj++;
			r++;
		}
		if(ans<k){
			while(r++){
				ans=0;
				for(int i=l;i<=r;i++){
					ans|=a[i];
				}
				if(ans==k){
					b[jj].l=l;
					b[jj].r=r;
					jj++;
					r++;
					break;
				}
				if(ans>k){
					break;
				}
			}
			
		}
		if(ans>k){
			while(l++){
				ans=0;
				for(int i=l;i<=r;i++){
					ans|=a[i];
				}
				if(ans==k){
					b[jj].l=l;
					b[jj].r=r;
					jj++;
					l++;
					break;
				}
				if(ans<k){
					break;
				}
			}
		}
		
	}
	int maxn=1,maxc;
	sort(b+1,b+jj,cmp);
//	for(int i=1;i<jj;i++){
//		cout<<b[i].l<<' '<<b[i].r<<'\n';
//	}
	for(int i=1;i<jj-1;i++){
		int ac=0;
		maxc=b[i].r;
		for(int j=i+1;j<jj;j++){
			if(maxc<b[j].l){
				ac++;
				maxc=b[j].r;
			}
		}
		maxn=max(maxn,ac);
	}
	cout<<maxn;
	return 0;
}
