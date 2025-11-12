#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[110],x,y,c,num,k;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	c=n*m;
	for(ll i=1;i<=c;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+1+c,cmp);
	for(ll i=1;i<=c;i++){
		if(a[i]==num){
			k=i;
			break;
		}
	}
	y=k/n;
	if(k%n!=0)y++;
	if(y%2==0){
		x=n-(k%n)-1;
		if(x==0)x=n;
	}else{
		x=k%n;
		if(x==0)x=n;
	}
	cout<<y<<" "<<x;
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
