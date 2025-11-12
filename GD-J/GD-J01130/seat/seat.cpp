#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,m,sum;
int a[1110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	int line=a[1];
	sort(a+1,a+1+sum,cmp);
	for(int i=1;i<=sum;i++){
		if(a[i]==line){
			line=i;
			break;
		}
	}
	int c=line/n+1;
	int b=line%n;
	if(line%n==0){
		b=n;
	}
	if(line==n){
		c=c-1;
	}
	if(c%2==0){
		b=n-line%n+1;
	}
	cout<<c<<" "<<b;
	return 0;
}


