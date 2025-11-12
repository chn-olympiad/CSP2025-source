#include<bits/stdc++.h>
using namespace std;
int aaa(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m=0,n=0;
	cin>>n>>m;
	long long a[n*m+7];
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int c=a[1],d=0,f=0;
	sort(a+1,a+m*n+1,aaa);
	for(int i=1;i<=n*m;i++){
		if(a[i]==c){
			d=i;
			break;
		}
	}
	f=d/n;
	d=d%n;
	if(d>0) f++;
	if(d==0) d=n;
	if(f%2==0){
		cout<<f<<" "<<m-d+1;
	}else{
		cout<<f<<" "<<d;
	}
	return 0;
}
