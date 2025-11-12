#include<bits/stdc++.h>
using namespace std;

int n,m,x,k;
int a[10004];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+nm+1);
	for(int i=1;i<=nm/2;i++){
		int tmp=a[i];
		a[i]=a[nm-i+1];
		a[nm-i+1]=tmp;
	}
	for(int i=1;i<=nm;i++){
		if(x==a[i]){
			k=i;
			break;
		}
	}
	int r=k-1;
	while(r>=n)r-=n;
	int p=k-1-r,q=0,aaa=0;
	for(int i=1;i<=10000;i++){
		if(aaa+n<=p){
			q++;;
			aaa+=n;
		}
		else break;
	}
	if(q%2==1){
		cout<<q+1<<" "<<n-r;
	}
	else {
		cout<<q+1<<" "<<r+1;
	}
	return 0;
}
