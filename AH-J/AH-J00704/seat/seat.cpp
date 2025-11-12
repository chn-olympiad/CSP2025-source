#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],tmp;
//1 2 3 4 5-> 5 4 3 2 1
void qs(long long q[],long long l,long long r){
	if(l>=r) return;
	int i=l-1,j=r+1,x=q[l];
	while(i<j){
		do i++;while(q[i]>x);
		do j--;while(q[j]<x);
		if(i<j) swap(q[i],q[j]);
	}
	qs(q,l,j);
	qs(q,j+1,r);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) tmp=a[i];
	}
	qs(a,1,n*m);
	long long co,x=1,y=1;
	for(long long i=1;i<=n*m;i++,co++){
		if(a[i]==tmp) break;
	}
	for(int i=1;i<=co;i++){
		if(x%2){
			(y==n)?(x++):(y++);
		}else{
			(y==1)?(x++):(y--);
		}
	}
	cout<<x<<' '<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
