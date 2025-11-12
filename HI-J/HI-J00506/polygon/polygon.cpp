#include<bits/stdc++.h>
using namespace std;
int x=0,sum=0;
int a[5009]={}; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>x;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}	
	int n=0;
	n=max(max(a[1],a[2]),a[3]);
	if(a[1]+a[2]+a[3] > n*2){
		sum++;
	}
	cout<<sum; 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
