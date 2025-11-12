#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r".stdin);
	freopen("seat.out","r".stdout);
	int n,m,s=0,sum=0,c=0,sum1=0;
	cin>>n>>m;
	s=n*m;
	int a[s];
	for(int i=0;i<=s;i++){
		if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	}
		sum1=a[s];
		c=a[1];
		cin>>a[i];
		if(a[i]>sum){
			sum=a[i];
		}
		if(a[i]<sum1){
			sum1=a[i];
		}
		
	}
	if(c==sum){
		cout<<1<<" "<<1;
	}
	else if(c==sum1){
		cout<<n<<" "<<m;
	}
	return 0;
}