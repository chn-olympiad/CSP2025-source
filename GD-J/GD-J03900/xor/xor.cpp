#include <iostream>
#include <algorithm>
using namespace std;
int n,k,a[500005],p,sum,f[500005],ans;
bool f2;
struct q{
	int l,r,len;
}b[500005];
bool cmp(q a,q b){
	return a.len<b.len;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=i;j<=n;j++){
			sum^=a[j];
			if(sum==k){
				p++;
				b[p].l=i;
				b[p].r=j;
				b[p].len=i-j+1;
			}
		}
	}
	sort(b+1,b+1+p,cmp);
	for(int i=1;i<=p;i++){
		f2=0;
		for(int j=b[i].l;j<=b[i].r;j++){
			if(f[j]==1){
				f2=1;
				break;
			}
		}
		if(f2){
			continue;
		}
		for(int j=b[i].l;j<=b[i].r;j++){
			f[j]=1;
		}
		ans++;
	}
	cout<<ans;
	return 0;
}
