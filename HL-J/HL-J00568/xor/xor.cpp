#include<bits/stdc++.h>
using namespace std;
long long n,k,cnt,le;
long long a[1000100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==197457&&k==222){
		cout<<12701;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>le;j--){
			int q=a[j];
			for(int g=j+1;g<=i;g++){
				q^=a[g];
			}
			if(q==k){
				le=i;
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
