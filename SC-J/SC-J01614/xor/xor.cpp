#include<bits/stdc++.h>
using namespace std;
long long k;
int n,a[500005],sum;
bool s1=true;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]!=1){
				s1=false;
				break;
			}
		}
		if(s1){
			cout<<n/2;
			return 0;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i;j<=n;j++){
			int d=a[i];
			for(int x=i+1;x<=j;x++){
				d=d^a[x];
			}
			if(d==k){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}