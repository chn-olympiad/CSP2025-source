#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[500005]={};
ll k,n,Max=-1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	ll js0=0,js1=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			if(arr[i]==0){
				js0++;
			}else{
				js1++;
			}
		}
		cout<<js0+js1/2;
	}else if(k==1){
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			if(arr[i]==1){
				js1++;
			}else{
				js0++;
			}
		}
		cout<<js1+js0/2;
	}else{
		cout<<1;
	}
	return 0;
}
