#include<iostream>
using namespace std;
int main(){
	int n,k,a[10000];
	cin>>n>>k;
	for(int i=1;i<n;i++)cin>>a[i];
	if(a[1]==0||a[2]==0)cout<<1;
	if(a[1]==0&&a[2]==0)cout<<2;
	else if(a[1]==a[2])cout<<1;
	return 0;
}