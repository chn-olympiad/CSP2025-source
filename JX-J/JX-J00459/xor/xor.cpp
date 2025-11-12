#include <bits/stdc++.h>
using namespace std;
bool fff1,fff2;
int n,k,a[500010];
long long ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0)fff1=1;
		if(a[i]>1)fff2=1;
	}
	if(n==1){
		if(k!=a[1]){
			cout<<0;
			return 0;
		}
		else{
			cout<<1;
			return 0;
		}
	}
	if(!fff1){
		cout<<n/2;
		return 0;
	}
	if(!fff2){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
			}
			cout<<ans;
			return 0;
		}else {
			for(int i=1;i<=n;i++)if(a[i]==0)ans++;
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1){
					ans++;
					a[i]=0;
					a[i+1]=0;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
