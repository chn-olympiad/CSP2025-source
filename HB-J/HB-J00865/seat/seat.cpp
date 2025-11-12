#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],r,c;
bool cnt(int a,int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int tot=a[0],sum;
	sort(a,a+n*m,cnt);
	for(int i=0;i<m*n;i++){
		if(tot==a[i]){
			sum=i+1;
		}
	}
	c=sum/n;
	if(c%2==1){
		r=sum-sum/n*n+1;
	}else{
		r=n-(sum-sum/n*n);
	}
	cout<<c<<" "<<r;
	return 0;
}
