#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
		
	int n,k;
	cin>>n>>k;
	int a[n];
	int ans=0;
	for(int i=1;i<=n;i++){
		int max1=0;
		for(int j=2;j<=n;j++){
			int ans=0;
			for(int z=i;z<=j;z++){
				ans+=a[z]^a[z+1];
			}
			if(ans==k){
				for(int l=i;l<=j;l++){
					max1=max(a[l],a[l+1]);
				}
			}
		}
		if(ans==0){
			ans=max1;
			break;
		}
		else{
			ans=max(ans,max1);
			break;
		}
	}
	cout<<ans;
		
	fclose(stdin);
    fclose(stdout);
	return 0;
}
