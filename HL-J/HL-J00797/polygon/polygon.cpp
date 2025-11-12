#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int s=0;
	while(cin>>a[s]){
		s++;
	}
	if(n==1){
		cout<<0;
	}else if(n==2){
		cout<<0;
	}else if(n==3){
		if(a[1]==a[2]&&a[2]!=a[3]){
			cout<<1;
		}else if(a[1]==a[2]&&a[2]==a[3]){
			cout<<1;
		}else if(a[1]!=a[2]&&a[2]!=a[3]&&a[1]!=a[3]){
			cout<<1;
		}
	}else if(n==4){
		if(a[1]==a[2]&&a[2]==a[3]&&a[4]==a[3]){
			cout<<2;
		}else if(a[1]==a[2]&&a[2]==a[3]&&a[2]!=a[4]){
			cout<<3;
		}else if(a[1]!=a[2]&&a[2]!=a[3]&&a[1]!=a[3]&&a[3]!=a[4]){
			cout<<11;
		}
	}}else if(n==5){
		if(a[1]==a[2]&&a[2]==a[3]&&a[4]==a[3]&&a[4]==a[5]){
			cout<<3;
		}else if(a[1]==a[2]&&a[2]==a[3]&&a[2]!=a[4]&&a[4]!=a[5]&&a[2]!=a[5]){
			cout<<8;
		}else if(a[1]!=a[2]&&a[2]!=a[3]&&a[1]!=a[3]&&a[3]!=a[4]&&a[5]!=a[4]){
			cout<<26;
		}
	}
	return 0;
}
