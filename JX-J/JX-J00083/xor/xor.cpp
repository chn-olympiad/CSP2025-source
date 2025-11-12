#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k,a[500005],la,lb,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			la++;
		}
		if(a[i]==0){
			lb++;
		}
	}
	if(k==0&&lb==0){
		cout<<(la/2);
		return 0;
	}
	if(k==0&&la==0){
		cout<<lb;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
			ans++;
			i++;
		}
		else if(a[i]==1){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
