#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[10005];
bool cmp(int a,int b){
	return a>b;
}
int main(){

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	int xm=a[1];
	sort(a+1,a+1+m*n,cmp);
	int t=0;
	for(int i=1;i<=m*n;i++){
		if(a[i]==xm){
			t=i;break;
		}
	}
	int q;
	q=t/n+1;
	if(t%n==0)q--;
	int p;
	if(q%2==1){
		p=t%n;
		if(t%n==0)p=n;
	}
	if(q%2==0){
		p=t%n;
		if(t%n==0)p=n;
		p=n-p+1;
	}
	cout<<q<<" "<<p;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
