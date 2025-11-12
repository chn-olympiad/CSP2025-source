#include<bits/stdc++.h>
using namespace std;
const int N=5010;
long long n,a[N],ans;
void d(){
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			long long maxn=0,h=0;
			for(int k=i;k<=j;k++){
				maxn=max(maxn,a[k]);
			} 
			for(int k=i;k<=j;k++){
				h+=a[k];
			} 
			if(h-(2*maxn)>0){
				ans++;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i];
	if(n<=3){
		long long maxn=0,h=0;
		maxn=max(maxn,max(a[2],max(a[1],a[3])));
		h=a[1]+a[2]+a[3];
		if(h-(2*maxn)>0){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	d();
	cout<<ans;
	return 0;
}

