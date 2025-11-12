#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200],b;
int id,c=1;
bool cmp(int n,int m){
	return n>m;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	b=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b) id=i;
	}
	if(id<=n){
		cout<<"1 "<<id;
		return 0;
	}
	else {
		while(id>=n){
			id-=n;
			c++;
		}
		if(c%2==0)
			cout<<c<<" "<<n+1-id;
		else cout<<c<<" "<<id;
	}
	return 0;
}
