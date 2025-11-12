#include<bits/stdc++.h>
using namespace std;
int arr[100001],num;
int n,k,m=0,mnm=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	while(n--){
		cin>>arr[m];
		m++;
	}
	for(int i=0;i<m;i++){
		num=num^arr[i];
		if(num==k){
			mnm++;
			num=0;
		}
	}
	cout<<mnm;
	return 0;
}
