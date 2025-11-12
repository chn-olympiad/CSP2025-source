#include<bits/stdc++.h>
using namespace std;
int k(int a){
	int sum=1;
	for(int i=1;i<=a;i++){
		sum*=i;
	}return sum;
}int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=3;i<=n;i++){
		sum+=k(n)/k(5-i)/k(i);
	}cout<<sum;
	return 0;
}