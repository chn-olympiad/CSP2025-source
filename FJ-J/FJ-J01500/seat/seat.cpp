#include<bits/stdc++.h>
using namespace std;
int n,m,a[105]={0},c=0,r=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[100]={0},c=0,r=0;
	cin>>n>>m; 
	int sum=n*m;
	for(int i=0;i<sum;i++) cin>>a[i];
	int x=a[0],p=0;
	sort(a,a+sum);
	for(int i=sum-1;i>=0;i--){
		if(x==a[i]){
			p=sum-i; break;
		}
	}
	if(p/n*n<p) c=(p/n)+1;
	else c=p/n;
	if(c%2!=0) r=p-((c-1)*n);
	else r=n-(p%n)+1;
	if(r>n) r-=n;
	cout<<c<<" "<<r;
	return 0;
} 

