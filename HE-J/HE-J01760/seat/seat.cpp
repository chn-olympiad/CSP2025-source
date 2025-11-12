#include<bits/stdc++.h> 
using namespace std;
int n,m,o,a[105],sumh=1,suml=1,sum;
int c,r;
int main(){
	cin>>n>>m;
	cin>>o;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>o)sum++;
	}
	if(sum<n)sumh+=sum;
	else sum++;
	while(sum>n){
		sum-=n;
		suml++;
		sumh=sum;
		}
	if(suml%2==0)sumh=n-sum+1;
	c=suml;r=sumh;
	cout<<c<<" "<<r<<endl;
	return 0;
}
