#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	 int n,m,sum;
	 cin>>n>>m;
	 int o=n*m;
	 for(int i=1;i<=o;i++){
	 	cin>>a[i];
	 }
	 int c=a[1];
	 sort(a+1,a+o+1);
	 for(int i=1;i<=o;i++){
	 	if(c==a[i]){
	 		sum=i;
	 		break;
		 }
	 }
	 int l=o-sum+1;
	int y=l/n+1;
	int x;
	if(y%2==0){
		x=n-l%n+1;	
	}else if(y%2!=0){
		x=l%n;
	}
	cout<<y<<" "<<x;
	
	
	
	return 0;
}
