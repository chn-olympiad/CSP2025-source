#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
unsigned int n,m,RsScore,c,r,p;
unsigned short a[101];
bool cmp(unsigned short a,unsigned short b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	RsScore=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==RsScore){
			p=i;
			break;
		}
	}
	c=(p-1)/n+1;
	r=p-n*(c-1);
	if(c%2==0)r=n-r+1;
	cout<<c<<' '<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
