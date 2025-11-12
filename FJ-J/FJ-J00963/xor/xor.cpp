#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum,y[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		y[i]=y[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int f=y[j]^y[i-1];
			if(f==k){
				sum++;
				i=j;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}

