#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m;
bool cmp(int a,int b){
	return a>b;
}
void f(int b){
	cout<<(b-1)/n+1<<' ';
	if((b/n)%2==0){
		cout<<b%n+1;
	}
	else{
		cout<<n-b%n;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[100];
	cin>>n>>m;
	cin>>a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m,cmp);
	for(int i=1;i<n*m;i++){
		if(a[i]<a[0]){
			f(i);
			return 0;
		}
	}
	f(n*m);
	return 0;
}
