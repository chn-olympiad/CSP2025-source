#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int b[105][105];
int cnt=0;
int ans=0;
int pm=0;
int x=0,y=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[++cnt];
			ans=a[1];
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(ans==a[i]){
			pm=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		
	}
	//ÐÐ x 
	if(pm%(2*n)==0){
		x=1;
	}else if((pm%(2*n))<=n){
		x=pm%(2*n);
	}else if((pm%(2*n))>n){
		x=(n+1)-pm%(2*n)%n;
	}
	//ÁÐ y 
	if((pm%(2*n))<=n){
		y=pm/(2*n)*2+1;
	}else if(pm%(2*n)==0){
		y=pm/(2*n)*2;
	}
	else if((pm%(2*n))>n){
		y=pm/(2*n)*2+2;
	}
	cout<<y<<" "<<x;
	return 0;
}
