#include<bits/stdc++.h>
using namespace std;
int a[5010];
int n=0,sum=0;

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		
	}
	for(int i = 3;i <= n;i++){
		sum += (n-i+1);
	}
	sum %= 998;
	sum %= 244;
	sum %= 353;
	cout<<sum;
	return 0;
}