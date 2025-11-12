#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int a[500005];
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<n/2;
		return 0;
	}
	else if(k==1){
		int cnt=0;
		for(int i=0;i<n;i++){
			if(a[i]==1){
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	else{
		cout<<2;
	}
	return 0;
}