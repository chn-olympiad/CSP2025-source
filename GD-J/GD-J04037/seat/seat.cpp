#include<bits/stdc++.h>
using namespace std;
int n,m,r,d,sum,c;
int st[110];
bool cmp(int a,int b){
	return a>b;
}
int x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++)cin>>st[i];
	r=st[1];
	sort(st+1,st+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		if(r==st[i]){
			d=i;
			break;	
		}
	}
	if(d%n==0){ 
		y=d/n;
		if(y%2==1){
			x=n;
		}
		else{
			x=1;
		}
	}
	else{
		y=d/n+1;
		if(y%2==1){
			x=d%n;
		}
		else{
			x=n-d%n+1;
		}
	}
	cout<<y<<" "<<x<<"\n";
	return 0;
}
