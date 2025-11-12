#include <bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	long long arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	long long top=LONG_MAX,z=0,p=-1;
	for(long long j=0;j<n;j++){
		top=LONG_MAX;
		for(long long i=j;i>p;i--){
			if(top==LONG_MAX){
				top=arr[i];
			}else{
				top^=arr[i];
			}
			if(top==m){
				z++;
				top=LONG_MAX;
				p=j;
				break;
			}
		}
	}
	cout<<z;
	return 0;
}
