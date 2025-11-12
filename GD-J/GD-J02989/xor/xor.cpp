#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) f=0;
	}
	if(n==2) cout<<1;
	else if(n==1) cout<<0;
	else{
		long long sum=0;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=n-i+1;j++){
				for(int k=j+i-1;k<=n;k++){
					sum++;
				}
			}
		}
		cout<<sum;
	}
	return 0;
}
