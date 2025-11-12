#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum,ans=0;
	for(int i=1;i<=n;i++){
		sum=a[i];
		if(sum==k){
			ans++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			sum=sum^a[j];
			if(sum==k){
				i=j;
				ans++;
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
