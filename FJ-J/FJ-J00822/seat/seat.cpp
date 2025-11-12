#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int id1;
bool cmp(int u,int v){
	return u>v;
}
int n1,m1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ss=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ss){
			id1=i;
			break;
		}
	}
	//cout<<"id1"<<" "<<id1<<endl;
	if(id1%m==0){
		n1=id1/m;
		if(n1%2==0){
			m1=1;
		}
		else m1=m;
	}
	else {
		int mod1=id1%m;
		n1=(id1-mod1)/m+1;
		if(n1%2==0){
			m1=m-mod1+1;
		}
		else m1=mod1;
	}
	cout<<n1<<" "<<m1;
	return 0;
}
