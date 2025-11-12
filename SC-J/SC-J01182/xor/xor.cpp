#include<bits/stdc++.h>
using namespace std;
struct mn{
	long long s,l;
}b[500005];
long long n,a[500005],k;
map<long long,long long> q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	b[0].s=0;
	q[0]=0;
	for(int i=1;i<=n;i++){
		int kl=0;
		scanf("%lld",&a[i]);
		b[i].s=(b[i-1].s^a[i]);
		if(a[i]==k){
			b[i].l=i;
		}else{
			kl=q[(k^b[i].s)];
			if(kl>0||(k^b[i].s)==0){
				b[i].l=kl;
			}else{
				b[i].l=-1;
			}
		}
		q[b[i].s]=i;
	}
	int r=0,ans=0;
	for(int i=1;i<=n;i++){
		if(b[i].l>=r){
			r=i;
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 