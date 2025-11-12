#include<bits/stdc++.h>
using namespace std;
int n,m;
int x,k;
int l,h;
int a[105];
bool cmp(int q,int p){
	return q>p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	x=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			k=i;
			break;
		}
	}
	h=k%n+n*(k%n==0);
	l=k/n+(k%n!=0);
	if(l%2==0) h=n-h+1;
	cout<<l<<" "<<h;
	return 0;
}