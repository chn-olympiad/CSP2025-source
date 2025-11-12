#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freoen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum[n*m];
	for (int i=0;i<n*m;i++){
		cin>>sum[i];
	}
	int a=sum[0],b,c,r;
	sort(sum,sum+n*m,cmp);
	for (int i=0;i<n*m;i++){
		if (sum[i]==a){
			b=i+1;
			break;
		}
	}
	if (b%n==0){
		c=b/n;
	}
	else{
		c=b/n+1;
	}
	if (c%2==1){
		if (b%n==0){
			r=n;
		}
		else{
			r=b%n;
		}
	}
	else{
		if (b%n==0){
			r=1;
		}
		else{
			r=n-b%n+1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
