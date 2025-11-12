#include<bits/stdc++.h>
using namespace std;
long long n=0,m=0,s=0,a[10009]={0},num=0,c=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	s=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=i+1;j<m*n;j++){
			if(a[i]<a[j]) swap(a[i],a[j]);
		}
	}
	for(int i=0;i<n*m;i++){
		if(a[i]==s){
			num=i;
			break;
		}
	}
	num+=1;
	c=int(num/n)+1*(int(num%n>0));
	cout<<c<<' ';
//	cout<<num<<'\n';
	if(c%2==1){
		if(num%n==0){
			cout<<n;
		}
		else cout<<num%n<<'\n';
	}
	else{
		if(num%n==0){
			cout<<1;
		}
		else cout<<n-num%n+1<<'\n';
	}
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/
