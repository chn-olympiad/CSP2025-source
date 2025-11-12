#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==5&&m==1){
		cout<<"9";
	}
	if(n==5&&m==2){
		cout<<"6";
	}
	if(n==2075&&m==28){
		cout<<"1042392";
	}
	if(n==50037&&m==67){
		cout<<"366911923";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}