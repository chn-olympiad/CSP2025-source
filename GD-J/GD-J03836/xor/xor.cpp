#include<bits/stdc++.h>
using namespace std;
int arr[int(1e5+10)];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,t=0,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(i==1||t==-1) t=arr[i];
		else t ^=arr[i];
		if(t==k){
			t=-1;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
