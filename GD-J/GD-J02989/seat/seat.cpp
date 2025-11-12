#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int a[N];
int n,m,sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i>1&&a[i]>a[1]){
			sum++;
		}
	}
	cout<<sum/n+1<<" ";
	if((sum/n+1)%2==1){
		cout<<sum%n+1;
	}else{
		cout<<n-sum%n;
	}
	return 0;
}
