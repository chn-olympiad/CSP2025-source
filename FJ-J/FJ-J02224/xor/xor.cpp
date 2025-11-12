#include<bits/stdc++.h>
using namespace std;
int n,k,m=1,sum=0;
int a[500005];
int x[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=x[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j<=i;j++){
			if((x[i]^x[j-1])==k){
				sum++;
				m=i+1;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}
