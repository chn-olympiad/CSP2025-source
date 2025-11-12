#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,p,ans,a[N];
long long b[N];
void special() {
	for(int i=1; i<=n; i++) {
		if(a[i]==0) {
			ans++;
			continue;
		}
		if(a[i]==a[i-1]) {
			ans++;
			a[i-1]=a[i]=-1;
		}
	}
	cout<<ans;
	exit(0);
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	if(k==0) {
		special();
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			continue;
		}else if(a[i]==k){
			ans++;
			continue;
		}
		b[++p]=a[i];
	}
	for(int i=1;i<=n;i++){
		if(b[i]==-1){
			continue;
		}
		if(b[i]^b[i+1]==k){
			ans++;
			b[i+1]=b[i]=-1;
		}else if(b[i]^b[i+1]^b[i+2]==k){
			ans++;
			b[i+2]=b[i+1]=b[i]=-1;
		}else if(b[i]^b[i+1]^b[i+2]^b[i+3]==k){
			ans++;
			b[i+3]=b[i+2]=b[i+1]=b[i]=-1;
		}
	}
	if(ans>n){
		cout<<n;
		return 0;
	}
	cout<<ans<<endl;
	return 0;
}
