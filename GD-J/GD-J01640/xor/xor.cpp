#include<bits/stdc++.h>
using namespace std;
int ans;
int a[500005],t[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			t[i]=1;
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		if(t[i]==1)continue;
		int sum=a[i];
		for(int j=i+1;j<=n;j++){
			if(t[j]==1)break;
			sum^=a[j];
			if(sum==k){
				ans++;
				for(int k=i;k<=j;k++){
					t[k]=1;
				}
				break;
			}
		}
	}
	cout<<ans;
	return 0; 
} 
