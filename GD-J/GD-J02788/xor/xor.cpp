#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long ans=0;int n;
long long k,b;
long long a[N];int m=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>b;a[i]=a[i-1]^b;
	}
	if(a[n]<2){
		for(int i=1;i<=n;i++){
			if((a[i]^m)==k){
				ans++;
				m=a[i];
			}
		}
		cout<<ans;
	}else {
		a[0]=0;
		for(int i=1;i<=n;i++){
			for(int j=m;j<i;j++){
				if((a[i]^a[j])==k){
					ans++;
					m=i;
					break;
				}
			}
		}
		cout<<ans;
	}
	
	return 0;
}

