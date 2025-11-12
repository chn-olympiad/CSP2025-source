#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,nextt=1,ans;
ll a[500500],addn;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			nextt=i+1;
		}
		addn=a[i];
		for(int j=i-1;j>=nextt;j--){
			if((addn^a[j])==k){
				ans++;
				nextt=i+1;
				break;
			}else{
				addn=(addn^a[j]);
			}
		}
	}
	cout<<ans;
	return 0;
}
