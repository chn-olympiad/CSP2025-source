#include<bits/stdc++.h>
using namespace std;
unsigned long long s;
int n,a[5010];
unsigned long long c(int m,int n){
	bool p=false;
	if(n*2>m)n=m-n;
	unsigned long long x=1,y=1;
	for(int i=1;i<=n;i++)
		x*=i;
	for(int i=m-n+1;i<=m;i++){
		y*=i;
		if(y%x==0&&!p){
			y=y/x;
			p=true;
		}
	}
	return y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=3;i<=n;i++)
		s+=c(n,i);
	cout<<s;
	return 0;
}
