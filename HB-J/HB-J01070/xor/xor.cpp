#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0||k==1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k)sum++;
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int cnt=a[i];
			for(int k=i+1;k<=j;k++){
				cnt^=a[k];
			}
			if(cnt==k)ans++;
		}
	}
	cout<<ans;
	return 0;
}
