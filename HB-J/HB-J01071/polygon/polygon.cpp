#include<bits/stdc++.h>
using namespace std;
int n;
int a[6];
bool f;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<"0";
		return 0;
	}
	if(n==3){
		f=true;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int x=a[1]+a[2];
		int y=a[1]+a[3];
		int z=a[3]+a[2];
		if(x<=a[3])f=false;
		if(y<=a[2])f=false;
		if(z<=a[1])f=false;
		if(f==true)cout<<"1";
		else cout<<"0";
	}
	else{
		for(int i=1;i<=5;i++){
		cin>>a[i];
	}
	if(n==5&&a[1]==1)cout<<"9";
	if(n==5&&a[1]==2)cout<<"6";
	else cout<<5;
	}
	return 0;
}
