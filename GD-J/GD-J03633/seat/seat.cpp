#include <iostream>
#include <vector> 
#include <algorithm> 
#include <cstdio>
#define pb push_back
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int id=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			id=i;
			break;
		}
	}
//	cout<<id<<endl; 
	int y=id/n,x=0;
	if(id%n!=0){
		y++;
		if(y%2==1)
			x=id%n;
		else
			x=(n-(id%n)+1);
	}
	else{
		if(y%2==1)
			x=n;
		else
			x=1;
	}
	cout<<y<<' '<<x<<endl;
	return 0;
}
