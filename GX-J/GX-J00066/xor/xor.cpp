#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000000];
int main(){
	int sum1=0,sum2=0;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	a[0]=-101010-1000000000;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==a[i-1]&&a[i]!=0){
			sum2++;
		}
		if(a[i]==1){
			sum1++;
		}else if(a[i]==0){
			sum2++;
		}
	}
	if(m==0){
		cout<<sum2;
	}else{
		cout<<sum1;
	}
	return 0;
}
	
