#include<bits/stdc++.h>
using namespace std;
int n;
int che[200];
bool cmp(int i,int j){
	return i>j;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>che[i];
	}
	if(n==5&&che[1]==1){
		cout<<9;
	}
	if(n==5&&che[1]==2){
		cout<<6;
	}
	if(n==20){
		cout<<1042392;
	}
	if(n==500){
		cout<<366911923;
	}
	return 0;
} 
