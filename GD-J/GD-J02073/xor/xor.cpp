#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,len,ans=1,a[N];
struct node{
	int l,r;
}v[N];
bool cmp(node x,node y){
	if(x.l==y.l){
		return x.r<y.r;
	}
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int l=1;l<=n;++l){
		if(a[l]==k){
			v[++len]=node{l,l};
		}
		int sum=a[l];
		for(int r=l+1;r<=n;++r){
			sum^=a[r];
			if(sum==k){
				v[++len]=node{l,r};
			}
		}
	}
	sort(v+1,v+len+1,cmp);
//	for(int i=1;i<=len;++i){
//		cout<<v[i].l<<","<<v[i].r<<"\n";
//	}
	int l=v[1].l,r=v[1].r;
	for(int i=2;i<=len;++i){
		if(v[i].l>r){
			++ans;
			r=v[i].r;
		}
	}
	printf("%d",ans);
	return 0;
}
