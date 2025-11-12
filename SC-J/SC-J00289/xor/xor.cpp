#include<bits/stdc++.h>
using namespace std;
struct st{
	long long p,v;
};
bool pd(st x,st y){
	return x.v==y.v?x.p<y.p:x.v<y.v;
}
long long n,k,a[500005],b[500005],c[500005],ans=0;
st d[100005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=b[i-1]^a[i];
		c[i]=k^b[i];
		d[i].p=i;
		d[i].v=b[i];
	}d[0].p=0;d[0].v=0;c[0]=k;
	sort(d,d+n+1,pd);
	for(long long i=0;i<n;i++){
		long long l=0,r=n,mid,s=0;
		bool flag=0;
		while(l<=r){
			mid=(l+r)/2;
			if(c[i]==d[mid].v&&i<d[mid].p){
				flag=1;
				s=d[mid].p;
			}
			if(c[i]>d[mid].v) l=mid+1;
			else if(c[i]<d[mid].v) r=mid-1;
			else if(d[mid].p<=i) l=mid+1;
			else r=mid-1;
		}if(flag){
			ans++;
			i=s-1;
		}
	}
	cout<<ans;
}