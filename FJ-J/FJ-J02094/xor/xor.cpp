#include <bits/stdc++.h>
using namespace std;
int n,k;
long long a[500005];
int cnt,sum=-1;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(sum==-1){
			sum=a[i];
			continue;
		}
		sum=sum^a[i];
		if(sum==k){
			cnt++;
			sum=-1;
		}
	}
	cout<<cnt;
	return 0;
} 
