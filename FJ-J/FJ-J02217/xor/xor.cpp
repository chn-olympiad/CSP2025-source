#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,summ=0;
	cin>>n>>k;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		if(a[i]==1) summ++;
	}
	if(k==0 && summ==n){
		cout<<n;
		return 0;
	}
	else{
		int sum=0;
		int num=0;
		for(int i=0;i<n;i++){
			if(a[i]==1) num++;
			if(num%2==0 && k==0) sum++,num=0;
			else if(num%2==1 && k==1) sum++,num=0;
		}
		cout<<sum;
	}
	return 0;
}
