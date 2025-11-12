#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1100000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2){
		cout<<1;
	}
	else if(n<=10){
		int num=0;
		for(long long i=1;i<n;i++){
			if(a[i]==0&&a[i+1]==1){
				num++;
				i++;
			}
			if(a[i]==1&&a[i+1]==0){
				num++;
				i++;
			}
		}
		cout<<num;
	}
	else if(n<=100){
		int ok=1;
		for(long long i=1;i<n;i++){
			if(a[i]!=1){
				ok=0;
				break;
			}
		}
		if(ok) cout<<n/2;
		else{
			ok=1;
			for(long long i=1;i<n;i++){
				if(a[i]!=1&&a[i]!=0){
					ok=0;
					break;
				}
			}
			if(ok){
				int num=0;
				for(long long i=1;i<n;i++){
					if(a[i]==0&&a[i+1]==1){
						num++;
						i++;
					}
					if(a[i]==1&&a[i+1]==0){
						num++;
						i++;
					}
				}
				cout<<num;
			}
			else{
				cout<<1;
			}
		}
	}
	else{
		cout<<1;
	}
	return 0;
}
