#include "bits/stdc++.h"
using namespace std;
int a[110],b[20][20];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,t,i,x,y;
	cin>>m>>n;
    for(i=1;i<=m*n;i++)cin>>a[i];
    if(m==1&&n==1){
    	cout<<"1"<<" "<<"1";
    	return 0;
	}
    t=a[1];
    sort(a+1,a+m*n+1,cmp);
    for(i=1;i<=m*n;i++)if(a[i]==t)t=i;
    if(t%m==0)x=t/m;
    else x=t/m+1;
    if(x%2==1){
    	if(t%m==0)y=m;
    	else y=t%m;
	}
	else{
		if(t%m==0)y=1;
		else y=m+1-(t%m);
	}
	cout<<x<<" "<<y;
	return 0;
} 

