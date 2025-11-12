#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int b=m*n;
	for(int i=1;i<=b;i++){
		cin>>a[i];
	}
	int x=a[1],j;
	sort(a+1,a+b+1);
	for(int i=1;i<=b;i++){
		if(a[i]==x){
			j=i;
			break;
		}
	}
	j=b-j+1;
	int c,r;
	if(j%n==0) c=j/n;
	else if(j%n!=0) c=j/n+1;
	if(c%2==0) r=n-j%n+1;
	else if(c%2==1) r=j%n;
	if(r==0) r=n;
	cout<<c<<" "<<r;
	return 0;
}
