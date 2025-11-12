#include<bits/stdc++.h>
using namespace std;
int n,a[10001],cnt;
long long sum;
bool c(int a, int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt++;
	}
	for(int i=cnt-1;i>=1;i--){
		sum+=i;
	}
	cout<<sum-1;
	
	
	return 0;
} 
