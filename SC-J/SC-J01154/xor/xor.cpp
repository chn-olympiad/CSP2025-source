#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,flag,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
	}
	if(flag==0){
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans=(a[i]+ans)%2;
		if(ans==k){
			cnt++;
			ans=0;
		}
	}
	cout<<cnt;
	return 0;
} 