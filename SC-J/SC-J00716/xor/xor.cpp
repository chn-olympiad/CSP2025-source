#include<bits/stdc++.h>
using namespace std;
int a[100010],cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int j=1;
	int ans;
	for(int i=1;i<=n;i++){
		ans=a[i];
		if(ans==k){
			cnt++;
			j++;
		}
		while(j<=n){
			ans^=(a[i]^a[j]);
			if(ans==k){
				cnt++;
				continue;
			}
			j++;
		}
	}
	cout<<cnt;
	return 0;
} 