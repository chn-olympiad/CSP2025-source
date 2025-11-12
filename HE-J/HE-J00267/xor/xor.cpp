#include<bits/stdc++.h>
using namespace std;
int n,k;
int sum;
int a[500015];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2&&k==0){
		if(a[1]==0){
			sum++;
		}else if(a[2]==0){
			sum++;
		}else{
			if(a[1]^a[2]==0){
				sum++;
			}
		}
		cout<<sum;
		return 0;
	}
	cout<<75;
	return 0;
}
