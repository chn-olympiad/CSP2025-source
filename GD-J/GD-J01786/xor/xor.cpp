#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0,w=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
		for(int j=i-1;j>=w;j--){
			if(int(a[i]^a[j])==k){
				cnt++;
				w=i;
			}
		}
	}
	cout<<cnt;
	return 0;
}
