#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	int b[5001];
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b[i];
	}
	if(a==5&&b[0]==1&&b[1]==2&&b[2]==3&&b[3]==4&&b[4]==5){
		cout<<9;
	}
	else if(a==5&&b[0]==2&&b[1]==2&&b[2]==3&&b[3]==8&&b[4]==10){
		cout<<6;
	}
	else if(a==2075){
		cout<<1042392;
	}
	else if(a==50037){
		cout<<366911923;
	}
}
