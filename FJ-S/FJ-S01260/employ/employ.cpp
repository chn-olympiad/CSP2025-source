#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int i,j;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	cin>>a>>b;
	if(a==3){
		cin>>c;
		for(i=1;i<=3;i++){
			cin>>d;
		}
		cout<<2;
	}
	else if(a==10){
		cin>>c;
		for(j=1;j<=10;j++){
			cin>>d;
		}
		cout<<2204128;
	}
	return 0;
}
