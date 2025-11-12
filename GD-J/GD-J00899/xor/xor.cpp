#include<bits/stdc++.h>
using namespace std;
int arr[100000+100];
bool vis[100000+100];
int ans;
int n,k;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]==k){
			ans++;
			vis[i]=1;
		}
	}
	if(k==0){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int sum=arr[i];
		if(arr[i]==k||(!vis[i])){
			continue;
		}
		for(int j=i+1;j<=n&&(!vis[j]);j++){
			sum&=arr[j];
			if(sum==k){
				ans++;
				int x=j;
				while(!vis[x]){
					vis[x]=1;
					x--;
				}
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
