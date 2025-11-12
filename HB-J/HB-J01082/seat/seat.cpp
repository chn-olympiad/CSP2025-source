#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],st[105][105];
bool cmp(int p1,int p2){
	return p1>p2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num=n*m,rr=0,posr=1,c=1,r=1;
	for(int i=1;i<=num;i++){
		cin>>a[i];//input score
	}
	rr=a[1];
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num;i++){
		if(a[i]==rr){
			posr=i;//RR's position
		}
	}
	if(posr%n==0)
	{
		c=posr/n;
	}
	else{
		c=posr/n+1;
	}
	//c=ceil(posr/n);
	//r=n-(posr%n)+1;
	if(c%2==0){
		if(posr%n!=0) r=n-(posr%n)+1;
		else r=1;
	}
	else{
		if(posr%n!=0) r=posr%n;
		else r=n;
	}
	cout<</*posr<<" "<<*/c<<" "<<r;
	return 0;
}
