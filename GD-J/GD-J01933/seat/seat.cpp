#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int a[N];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	int p=a[1];
	sort(a+1,a+sum+1);
	int num1 = lower_bound(a+1,a+sum+1,p)-a;
	int c,r;
	int num2=sum-num1+1;
	c=ceil(num2/(n*1.0));
	if(c%2==0)r=n-(num2%n)+1;
	else{
		if(num2%n==0)r=n;
		else r=num2%n;
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
