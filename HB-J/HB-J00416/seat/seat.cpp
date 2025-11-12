#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int a[m*n];
	for(int i=0;i<m*n;i++)
		cin>>a[i];
	int score=a[0];
	sort(a,a+m*n,cmp);
	int where=0;
	for(int i=0;i<m*n;i++)
		if(a[i]==score)
			where=i+1;
	cout<<where<<endl;
	int c=0,r=0;
	if(where%n!=0)
		c=where/n+1;
	else
		c=where/n;
	if(c%2==1){
		if(where%n==0)
			r=1;
		else
			r=where%n;
	}
	else
		r=where%n+1;
	cout<<c<<" "<<r;
	return 0;
}
