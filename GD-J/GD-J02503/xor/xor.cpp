#include<bits/stdc++.h>
using namespace std;
int n,k,a[100010],b[100010]={0},cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			b[i]=a[i];
			continue;
		}
		b[i]=b[i-1]^a[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[j]-b[i-1]==k){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
} 
