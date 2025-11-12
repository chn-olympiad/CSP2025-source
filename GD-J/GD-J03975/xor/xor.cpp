#include <iostream>
using namespace std;
int n,k,a[500005],as[500005],t[1100000],f[500005],dp[500005],md[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>k;
	for(int i=0;i<=n;i++){
		t[i]=-1;
	}
	t[k]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		as[i]=as[i-1]^a[i];
		if(t[as[i]]!=-1){
			f[i]=t[as[i]]+1;
		}
		t[as[i]^k]=i;
	}
	for(int i=1;i<=n;i++){
		if(f[i]){
			dp[i]=md[f[i]-1]+1;
			md[i]=max(md[i-1],dp[i]);
		}
		else{
			dp[i]=md[i-1];
			md[i]=md[i-1];
		}
	}
	cout<<md[n]<<endl;
	return 0;
}
