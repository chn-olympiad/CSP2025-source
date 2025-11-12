#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i-1]^a[i];
	}
	int t=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if((a[j]^a[i])==k){
				t++;i=j-1;break;
			}
		}
	}
	cout<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
}