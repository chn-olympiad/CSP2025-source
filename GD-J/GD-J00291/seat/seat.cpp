#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,m,l,a[N],xx,yy;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	l=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==l){
			l=i;
			break;
		}
	if(l%n==0){
		yy=l/n;
		if(yy%2==0) xx=1;
		 else xx=n;
	}
	 else{
	 	yy=l/n+1;
	 	if(yy%2==0) xx=n-(l%n)+1;
	 	 else xx=l%n;
	 }
	cout<<yy<<" "<<xx;
	return 0;
}
