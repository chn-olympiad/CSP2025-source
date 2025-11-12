#include<bits/stdc++.h>
using namespace std;
int main{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num=0;
	cin>>n>>m;
	l=n*m;
	int a[l]={0},b[l]={0},c[l]={0};
	for(int i=0;i<=l;i++){
		cin>>a[i];
	}
	for(int i=1;i<=l;i++){
		if(a[1]<a[i+1]){
			num++;	
		}
	}
	c=++num/m;
	if(++num/r%2==0){
		r=4-++num%r;
	}
	cout<<c<<r<<endl;

	return 0;
}
