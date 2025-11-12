#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans;
bool b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			b[i]=1;
			continue;
		}else{
			if(b[i-1]==0){
				a[i]=a[i]^a[i-1];
			}
			if(a[i]==k&&b[i]==0){
					b[i]=1;
					ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}