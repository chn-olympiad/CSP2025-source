#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
		cin>>a[i];
	int f=a[0];
	sort(a+0,a+n*m,cmp);	
	for(int i=0;i<n*m;i++){
		if(f==a[i]){
			f=i;
			break;
		}
	}
	int r=f/n+1,c;
	if((f/n)&1==1)
		c=n-(f%n);
	else
		c=1+(f%n);
	cout<<r<<" "<<c;
	return 0;
}