#include<bits/stdc++.h>
using namespace std;
int a[500005],sum[500005],n,k;
bool check(int x){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(cnt==x)return 1; 
		for(int j=1;j<=n;j++){
			if(sum[j]^sum[i-1]==k){
				i=j+1;cnt++;
				break;
			}
		}
	} 
	if(cnt==x)return 1;
	else return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				//cout<<i<<" "<<j<<"\n";
				i=j;ans++;
				break;
			}
		}
	} 
	cout<<ans;
	return 0;
} 
