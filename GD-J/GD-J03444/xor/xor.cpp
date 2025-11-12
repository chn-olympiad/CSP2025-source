#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,z=0;
	cin>>n>>k;
	vector<long long> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int temp;
		for(int j=i;j<n;j++){
			if(i==j){
				temp=a[i];
			}else{
				temp=(a[j]^temp);
			}
			if(temp==k){
				i=j;
				z++;
				break;
			}
		}
	}
	cout<<z;
}
