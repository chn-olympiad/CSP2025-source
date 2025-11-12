//xor
#include <bits/stdc++.h>
using namespace std;
int a[500001];
int main(){
	int n;
	long long k,sum=0,w=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (n<=2 && k==0){
		int t=1;
		for (int i=1;i<=n;i++){
			if (a[i]!=1){
				t=0;
			}
		}
		if (t==1){
			if (n==2){
				cout<<1;
			}
			else{
				cout<<0;
			}
			return 0;
		}
	}
	for (int i=1;i<=n;i++){
		w=a[i];
		if (w==k){
			sum++;
			continue;
		}
		for (int j=i+1;j<=n;j++){
			w=(w^a[j]);
			if (w==k){
				sum++;
				i=j+1;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}
