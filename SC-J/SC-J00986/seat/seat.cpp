#include<bits/stdc++.h>
using namespace std;
int a[1010];
int sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			sum++;
		}
	} 
	cout<<sum/n+1<<" ";
	if((sum/n+1)%2==0){
		cout<<n-sum%n;
	}else{
		cout<<sum%n+1;
	}
	return 0;
} 