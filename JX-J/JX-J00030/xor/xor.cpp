#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[500001]={};
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		long long s=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				s++;
			}
		}
		cout<<s;
		return 0;
	}
	if(k==1){
		long long s=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				s++;
			}
		}
		cout<<s;
		return 0;
	}
	return 0;
}
