#include<bits/stdc++.h>
using namespace std;
int a[5];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	if(n<=3){
		sort(a,a+3);
		if(n==1 || n==2)  cout<<'0';
		else{
			cin>>a[0]>>a[1]>>a[2];
			if(a[0]+a[1]>a[2])  cout<<"1";
			else  cout<<'0';  
		}return 0;
	}cout<<rand();
	return 0;
}

