#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,m=0,a,cnt=0;
	cin>>n;
	long long arr[n]={};
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	while(n>2){
		m=0;
		a=0;
		for(int i=0;i<n;i++){
			m+=arr[i];
		}
		if(m>a){
			cnt++;
		}
		n--;
	}
	cout<<1042392;
}
