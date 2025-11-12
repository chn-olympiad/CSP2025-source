#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1&&k==0){
		cout<<0;
	}
	else if(n<=200000&&k<=1){
		if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==a[i+1]){
					ans+=1;
					i+=1;
				}
				else{
					a[i+1]=1;
				}
			}
			cout<<ans;
			return 0;
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]!=a[i+1]){
					ans+=1;
					i+=1;
				}
				else{
					a[i+1]=0;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
