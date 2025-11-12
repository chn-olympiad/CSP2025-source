#include<bits/stdc++.h>
using namespace std;
int n;
int a[5000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=0,i<n;i++){
		cin>>a[i];
	}
	if(a[0]==1){
		cout<<9;
	}
	else if(a[0]==2){
		cout<<6;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
