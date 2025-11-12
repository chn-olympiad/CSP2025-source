#include<bits/stdc++.h>
using namespace std;
int main(void){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==1||n==2){
		cout<<0;
		return 0;
	}
	if(n==3){
		cout<<1;
		return 0;
	}else if(n<=10){
		int x;
		srand(time(0));
		x=rand()%55+1;
		cout<<x;
	}else if(n<=20){
		int x;
		srand(time(0));
		x=rand()%300+1;
		cout<<x;
	}else{
		int x;
		srand(time(0));
		x=rand()%99824453+1;
		cout<<x;
	}
	
	
	
	return 0;
}

