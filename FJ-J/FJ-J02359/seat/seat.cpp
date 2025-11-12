#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[105]={0};
	int n,m;
	cin>>n>>m;
	int sum=n*m;
	int c;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+sum+1);
	int x=1,y=1;
	for(int i=sum;i>=1;i--){
		if(a[i]==c){
			cout<<y<<" "<<x;
			break;
		}
		
		if(y%2==1) x++;
		
		if(y%2==0) x--;
		
		if(x==n+1){
			x=n;
			y++;
		}
		
		else if(x==0){
			x=1;
			y++;
		}
		
	}
	return 0;
}
