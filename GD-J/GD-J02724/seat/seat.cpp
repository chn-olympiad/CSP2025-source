#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[110],s,w,c,r;
int main(){
	ifstream fin("seat.in");
	ofstream fout("seat.out");
	fin>>n>>m;
	for(int i=1;i<=n*m;i++) fin>>a[i];	
	s=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
		if(a[i]==s){
			w=n*m-i+1;
			break;
		}
	c=(w-1)/n+1;
	r=w%m;
	if(c%2==0) r=n-r+1;
	if(r==0){
		if(c%2==0) r=n-r+1;
		else r=n-r;
	}
	fout<<c<<" "<<r;
	return 0;
} 
