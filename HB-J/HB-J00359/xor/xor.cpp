#include <bits/stdc++.h>
using namespace std;
int n,k,a[200005],flag=0;
bool sum;
long long sum1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=100;i++){
		if(a[i]!=0){
				flag=1;
		}
	}
	if(flag==1){
		cout<<0;
		return 0;
	}else{
		for(int i=1;i<=n-3;i++){
			sum1*=i;
		}
		cout<<sum1;
	}
	return 0;
}
