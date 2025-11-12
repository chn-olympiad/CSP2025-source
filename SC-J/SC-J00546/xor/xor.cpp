#include<bits/stdc++.h>
using namespace std;
int n,a[500010],k,ans,te;
int main(){
	freopen("xor.in","w",stdin);
	freopen("xor.out","r",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		te=a[i];
		if(te==k){
			ans++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			te=te^a[j];
			if(te==k){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
