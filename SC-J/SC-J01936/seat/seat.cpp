#include <bits/stdc++.h>
using namespace std;
int a[200];
int n,m;
int R,c,r;
bool cmp(int x,int y){
	return (x>y);
}
int main (){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	int num=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			num=i;
		}
	}
	if((num/n)%2==0||num%n==0){
		c=(num-1)/n+1;
		r=num-((num-1)/n)*n;
	} else {
		c=(num-1)/n+1;
		r=(n+1)-(num-((num-1)/n)*n);
	}
	cout<<c<<" "<<r;

	return 0;
}
