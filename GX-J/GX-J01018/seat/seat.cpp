#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int l[10000000]={};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long a,b,z,y=0,x1=0,y1=0;
	cin>>a>>b;
	for(int i=1;i<=a*b;i++){
		cin>>l[i];
	}
	z=l[1];
	sort(l+1,l+a*b,cmp);
	for(int i=1;i<=a*b;i++){
		if(l[i]==z){
			y=i;
		}
	}
	if(y<=a)x1=1;
	else x1=y/a+1;
	if(x1%2==1){
		if(y%a==0)y1=a;
		else y1=y%a;
	}
	else y1=a+1-(y%a);
	cout<<x1<<" "<<y1;
}
