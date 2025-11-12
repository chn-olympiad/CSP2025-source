#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500010];
int ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;){
		int j=i+1,t=a[i];
		if(t==k){
			ans++;
			i++;
			continue;			
		}
		for(;j<=n;j++){
			t^=a[j];
			if(t==k){
				ans++;
				i=j+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
