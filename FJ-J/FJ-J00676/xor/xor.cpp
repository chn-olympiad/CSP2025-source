#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		
	}	
	if (n<=2&&k==0){
		if (a[1]==0&&a[2]==0){
			cout<<2;
			return 0;
		}
		else if (a[1]==0){
			cout<<1;
			return 0;
		}
		else if (a[2]==0){
			cout<<1;
			return 0;
		}
		else if (a[1]^a[2]==0){
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	int ans;
	for (int i=1;i<=n;i++){
		if (a[i]==k){
			ans++;
			a[i]=-1;
		}
		
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			if (a[i]!=-1&&a[j]!=-1&&a[i]^a[j]==k){
				ans++;
				a[i]=-1;
			}
		}
	}
	cout<<ans;
}
