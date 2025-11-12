#include<bits/stdc++.h>
using namespace std;
int arr[5000+100];
int pre[5000+100];
int ans;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		pre[i]=arr[i]+pre[i-1];
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=i+3;j<=n;j++){
			sum=0;
			for(int x=i;x<=j;x++){
				if(arr[x]>sum){
					sum=arr[x];
				}
			}
			if(pre[j]-pre[i-1]>2*sum){
				ans++;
			}
		}
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
