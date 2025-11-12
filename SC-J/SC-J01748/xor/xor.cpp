#include<bits/stdc++.h>
using namespace std;
long long n,k,t=0;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=false;
	}
	if(k==0&&flag){
		cout<<n/2;
	} 
	if(k==0&&!flag){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				t++;
			}
		}
		for(int i=1;i<=n-1;i++){
			if(a[i]==1&&a[i+1]==1){
				t++;
				i++;
			}
		}
		cout<<t;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				t++;
			}
		}
		cout<<t;
	}
	return 0;
}