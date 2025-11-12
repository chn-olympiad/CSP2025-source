#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],cnt,k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnt++;
		}
	}
	if(cnt==n&&k==0){
		cout<<n/2;
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				ans++;
				a[i]=-1;
				a[i+1]=-1;
				i++;
			}
			
		}
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]&&a[i+1]==a[i+2]&&a[i]!=-1&&a[i+1]!=-1&&a[i+2]!=-1&&a[i]==0){
				ans++;
				a[i]=-1;
				a[i+1]=-1;
				a[i+2]=-1;
				i++;
				i++;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]&&a[i+1]==a[i+2]&&a[i]==0&&a[i]!=-1&&a[i+1]!=-1&&a[i+2]!=-1){
				ans++;
				a[i]=-1;
				a[i+1]=-1;
				a[i+2]=-1;
				i++;
				i++;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]&&a[i+1]!=a[i+2]&&a[i]==1&&a[i]!=-1&&a[i+1]!=-1&&a[i+2]!=-1){
				ans++;
				a[i]=-1;
				a[i+1]=-1;
				a[i+2]=-1;
				i++;
				i++;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]&&a[i+1]!=a[i+2]&&a[i]==1&&a[i]!=-1&&a[i+1]!=-1&&a[i+2]!=-1){
				ans++;
				a[i]=-1;
				a[i+1]=-1;
				a[i+2]=-1;
				i++;
				i++;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]&&a[i+1]!=a[i+2]&&a[i+2]!=a[i+3]&&a[i]!=-1&&a[i+1]!=-1&&a[i+2]!=-1&&a[i+3]!=-1){
				ans++;
				i++;
				i++;
				i++;
			}
		}
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				ans++;
				a[i]=-1;
				a[i+1]=-1;
				i++;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]&&a[i+1]==a[i+2]&&a[i]==1&&a[i]!=-1&&a[i+1]!=-1&&a[i+2]!=-1){
				ans++;
				a[i]=-1;
				a[i+1]=-1;
				a[i+2]=-1;
				i++;
				i++;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]&&a[i+1]==a[i+2]&&a[i]==1&&a[i]!=-1&&a[i+1]!=-1&&a[i+2]!=-1){
				ans++;
				a[i]=-1;
				a[i+1]=-1;
				a[i+2]=-1;
				i++;
				i++;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]&&a[i+1]!=a[i+2]&&a[i]==0&&a[i]!=-1&&a[i+1]!=-1&&a[i+2]!=-1){
				ans++;
				a[i]=-1;
				a[i+1]=-1;
				a[i+2]=-1;
				i++;
				i++;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]&&a[i+1]!=a[i+2]&&a[i]==0&&a[i]!=-1&&a[i+1]!=-1&&a[i+2]!=-1){
				ans++;
				a[i]=-1;
				a[i+1]=-1;
				a[i+2]=-1;
				i++;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
