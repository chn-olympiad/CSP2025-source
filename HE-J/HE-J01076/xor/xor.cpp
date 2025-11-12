#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
long long ss[500005];
int ll,lr;
long long sum=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			ss[i]=a[i];
		}
		else{
			ss[i]=ss[i-1]^a[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int p;
			if(i==1){
				p=ss[j];
			}
			else{
				p=(ss[j]^ss[i-1]);
			}
			if(p==k){
				if(i>lr&&j>=i){
					lr=j;
					sum++;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
