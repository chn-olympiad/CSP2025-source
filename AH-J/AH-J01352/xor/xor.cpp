#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005];
int s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=(a[i]^b[i-1]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((b[i-1]^b[j])==k){
				s++;
				cout<<i<<" "<<j<<endl;
				i=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;
	cout<<s;
	return 0;
}
