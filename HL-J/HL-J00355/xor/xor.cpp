#include<bits/stdc++.h>
using namespace std;
int a[500005],n,cnt;
long long k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=a[i];
		if(sum==k){
			cnt++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			sum^=a[j];
			if(sum==k){
				cnt++;
				i=j;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}