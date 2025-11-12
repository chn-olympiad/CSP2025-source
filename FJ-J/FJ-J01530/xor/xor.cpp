#include<iostream>
using namespace std;
long long n,k,f[500005],maxn,pre[500005],a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i<2){
			pre[1]=a[i];
		}else{
			pre[i]=pre[i-1]^a[i];
		}
		if(a[1]==k){
			f[1]++;
		}
	}
	for(int i=2;i<=n;i++){
		if(pre[i]==k||a[i]==k){
			f[i]=f[i-1]+1;
		}else{
			f[i]=f[i-1];
		}
	}
	cout<<f[n];
	return 0;
}
