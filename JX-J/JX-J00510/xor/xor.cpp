#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	int n,k;
	cin>>n>>k;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		a[i]=(a[i-1]^x);
	}
	int s=1,ans=0;
	for(int i=1;i<=n;i++){
		for(int j=s;j<=i;j++){
			if((a[i]^a[j-1])==k){
				ans++;
				s=i+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
