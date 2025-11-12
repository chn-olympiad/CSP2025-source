#include<bits/stdc++.h>
using namespace std;

const long long maxn=5*1e5+5;
long long n,k,bn,ans,cnt;
long long a[maxn],f[maxn];
struct hhh{
	long long be=0,en=0,le=0;
}h[maxn];

bool cmp(hhh x,hhh y){
	return x.en<y.en;
}

int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(long long i=1;i<=n;i++){
		bn=a[i];
		h[i].be=i;
		for(long long j=i+1;j<=n+1;j++){
			if(bn==k){
				h[i].en=j-1;	
				h[i].le=j-i;
				break;
			}
			if(j<=n) bn^=a[j];
		}
	}
	
	sort(h+1,h+1+n,cmp);
	
	for(long long i=1;i<=n;i++){
		if(h[i].en==0) continue;
		ans++;
		if(h[i].en>=h[i+1].be && i!=n){
			ans--;
		} 
		
	}
	/*for(int i=1;i<=n;i++){
			int l=f[i-1];
			for(int j=i-1;j>=1;j--){
				if(h[j].en>h[i].be)l--;
			}
			f[i]=max(f[i-1],f[i]+l);
	}*/
	cout<<ans;
	return 0;
} 
