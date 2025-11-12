#include<bits/stdc++.h>
using namespace std;
const int MAXN=5*1e5+5;
int n,k,a[MAXN],f0=0,ans=0,dp[MAXN],vst[MAXN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) f0++;
	}
	if(k==0){
		if(f0==0){
			f0=n;
			cout<<f0/2;
		}else{
			cout<<f0;
		}
	}
	else if(k==1){
		cout<<n-f0;
	}
	
	else{
		if(a[1]==k){
			dp[1]=vst[1]=1;
			ans++;
		}
		for(int i=2;i<=n;i++){
			int w=a[i];
			for(int j=i;!vst[j] && j>0;j--){
				if(w==k){
					for(int p=j;p<=i;p++) vst[p]=1;
					ans++;
					break;
				}else{
					w=(w^a[j-1]);
				}
			}
		}
		cout<<ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}