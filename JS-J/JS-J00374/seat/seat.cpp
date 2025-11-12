#include<bits/stdc++.h>
using namespace std;
int n,m;
int stu[1100];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>stu[i];
	}
	int aaa=stu[1],x=0;
	sort(stu+1,stu+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(stu[i]==aaa){
			x=i;
			break;
		}
	}
	int a=x/n,b=x%n,xx,yy;
	if(b!=0) xx=a+1,yy=a%2?n-b+1:b;
	else xx=a,yy=n;
	cout<<xx<<' '<<yy;
//	cout<<endl<<a<<' '<<b<<endl<<x;
	return 0;
}
