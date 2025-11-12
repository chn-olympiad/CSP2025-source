#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,xm,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		xm=a[1];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==xm){
			sum++;
			break;
		}else{        
			sum++;    
		}             
	}               
 	int l,h,y,man;
	y=sum%m;
	if(y==0){
		l=sum/m;
	}else{
		l=sum/m+1;
	}
	man=sum-(l-1)*m;
	if(l%2!=0){
		h=man;
	}else if(l%2==0){
		h=m-man+1;
	}
	cout<<l<<" "<<h;
	return 0;
}
