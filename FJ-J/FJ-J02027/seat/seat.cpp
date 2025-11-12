#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1080];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int j=a[1];
	sort(a+1,n*m+a+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==j){
			j=n*m-i;
			break;
		}
	}
	int x=j/n+1;
	int y=0;
	if(x%2==0){
		y=n-j%m;
	}
	else{
		y=j%m+1;
	}
	cout<<x<<" "<<y<<endl;
	return 0;
} 
