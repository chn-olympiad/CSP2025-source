#include <iostream>
using namespace std;
int a[600005],js[600005]={0};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k&&js[a[i]]==0){
			ans++;
			js[a[i]]=1;
		}else{
			if(js[a[i]]==0&&js[a[i+1]]==0&&i<n){
				if(sum==0){
					sum=(a[i]^a[i+1]);
				}else{
					sum=(sum^a[i+1]);
				}
				if(sum==k){
					sum=0;
					ans++;
					js[a[i]]=1;
					js[a[i+1]]=1;
				}
			}
		}
		
	}
	cout<<ans;
	return 0;
}
