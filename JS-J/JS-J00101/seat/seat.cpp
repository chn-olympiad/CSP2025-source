#include<bits/stdc++.h>
using namespace std;
int n,m,lie,hang;
int a[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int s;
	cin>>n>>m;
	s=n*m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int y=a[0];
	sort(a,a+s);
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==y){
			y=s-i;
		}
		//cout<<a[i]<<" ";
	}
	
	//cout<<y<<" ";
	if(y%n==0)lie=y/n;
	else lie=y/n+1;
	//<<lie;
	if(lie%2==1){
		if(y%n==0)hang=4;
		else hang=y%n;
	}
	else{
		if(y%n==0)hang=1;
		else
		{
			hang=n-y%n+1;
			//cout<<hang<<" ";
		}
			 
	}
	cout<<lie<<" "<<hang;
	return 0;
}
