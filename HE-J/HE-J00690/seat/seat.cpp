#include<bits/stdc++.h>
using namespace std;
int n,m,a[230],weizhi,x,y;
int main(){
	cin>>n>>m;
	for (int i=0;i<n*m;i++) cin>>a[i];
	int r=a[0];
	sort (a,a+n*m);
	for (int i=n*m;i>0;i--){
		if (a[i]==r) {
			weizhi =n*m-i;
			break;}
	}
	if(weizhi%n==0) x=weizhi/n;
	else x=weizhi/n+1;
	if (x%2==0) y=weizhi%n+1;
	else y=n-weizhi%n;
	cout<<x<<" "<<y;
	return 0;
}
