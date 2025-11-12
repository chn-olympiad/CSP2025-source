#include <bits/stdc++.h>
using namespace std;
const long long N=1e5*5+10;
long long n,k1,a[N],sum,x=1,ll,rr,ans,xx=1;
struct q{
	long long l,r,c;
}b[N],d[N];
bool cmp(q x,q y){
	return x.c<y.c;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k1;
	for(int i=1;i<=n;i=i+1){
		cin>>a[i];
	}
	for(int i=1;i<=n;i=i+1){
		for(int j=0;j<=n-i;j=j+1){
			sum=0;
			for(int k=i;k<=i+j;k=k+1){
				sum=sum^a[k];
			}
			if(sum==k1){
				b[x].l=i;
				b[x].r=i+j;
				b[x].c=j;
				x=x+1;
			}
		}
	}
	sort(b+1,b+x,cmp);
//	for(int i=1;i<x;i=i+1){
//		cout<<b[i].l<<" "<<b[i].r<<" "<<b[i].c<<endl;
//	}
	x=x-1;
//	cout<<endl;
	for(int i=1;i<=x;i=i+1){
		int bj=0;
		for(int j=1;j<=ans;j=j+1){
			if(b[i].l>d[j].l||b[i].r<d[j].l){
				
			}
			else{
				bj=1;
				break;
			}
		}
		if(bj==0){
			d[xx].l=b[i].l;
			d[xx].r=b[i].r;
			ans=ans+1;
			xx=xx+1;
//			cout<<b[i].l<<" "<<b[i].r<<" "<<b[i].c<<endl;
		}
		
	}
	cout<<ans;
	return 0;
}
