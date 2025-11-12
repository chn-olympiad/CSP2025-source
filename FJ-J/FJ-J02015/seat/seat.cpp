#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[110]={};
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++)	cin>>a[i];
	int x,y,h=a[1];
	sort(a+1,a+1+t);
	for(int i=t;i>=1;i--){
		int k=t-i;
		if(a[i]==h&&(k/n)%2!=0){
			x=k/n+1;	
			y=n-k%n;
		}
		else if(a[i]==h&&(k/n)%2==0){
			x=k/n+1;
			y=k%n+1;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
