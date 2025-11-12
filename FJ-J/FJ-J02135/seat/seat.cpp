#include <bits/stdc++.h>
using namespace std; 
int n,m,s[10005],t,x,y11,y22,yy;
int main(){
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int a=s[1];
	sort(s+1,s+n*m+1);
	for (int i=1;i<=n*m;i++){
		if (s[i]==a){
			t=i;
			break;
		}
	}
	x=t%n;
	y11=t%n;
	y22=t/n;
	if (y11==0){
		if(y22%2==0){
			yy=1;
		}
		else{
			yy=n;
		}
	}
	else{
		if(y22%2==0){
			yy=y11;
		}
		else{
			yy=n-y11+1;
		}
	}
	if(x==0){
		x=t/n+1;
	}
	cout<<x<<" "<<yy;
	return 0;
}
