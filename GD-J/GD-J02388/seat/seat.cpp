#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	int n,m,x=1,y=1,k;
	cin>>n>>m;
	k=n*m;
	cout<<k;
	int s=1;
	for(int i=0;i<k;i++){
		cin>>a[i];
	if(a[1]<a[1+s] && x<=m){
	x++;
	s++;
	continue;
}
	else if(x>m && a[1]<a[1+s]){
	y++;
	s++;
	m--;
}
}
cout<<x<<y;
	return 0;
}
