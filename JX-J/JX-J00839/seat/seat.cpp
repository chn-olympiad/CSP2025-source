#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int a,int b){
	return a>b;
}	
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}	
	int r=a[0];
	sort(a,a+n*m,cmp);
	int id;
	for(int i=0;i<n*m;i++){
		if(a[i]==r){
			id=i+1;
			break;
		}
	}	
	int x=id/n,y=id%n;
	if(id%n!=0){
		x++;
	}	
	if(x%2==1){
		if(y==0){
			y=n;
		}	
	}	
	else{
		if(y==0){
			y=1;
		}	
		else y=n-y+1;
	}	
	cout<<x<<" "<<y;
	return 0;
}
