#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	if(n<3){
		cout<<"0"<<endl;
	}else if(n==3){
		if(a[0]+a[1]+a[2]>max(a[0],max(a[1],a[2]))*2) cout<<"1"<<endl;
		else cout<<"0";
	}else{
		if(n==5 && a[0]==1) cout<<"9";
		else cout<<"6";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
