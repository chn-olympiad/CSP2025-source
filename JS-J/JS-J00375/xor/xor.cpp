#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt,ans,r,c;
struct nd{
	int l,r;
}b[500005];
bool cmp(nd x,nd y){
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i-1]^a[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((a[j]^a[i])==k){
				b[++cnt].l=i+1,b[cnt].r=j;
			}
		}
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(r<b[i].l){
			c++,r=b[i].r;
		}
		else{
			r=min(r,b[i].r);
		}
	}
	cout<<c;
	return 0;
}
