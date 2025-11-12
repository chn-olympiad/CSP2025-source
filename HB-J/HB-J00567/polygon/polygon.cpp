#include<bits/stdc++.h>
using namespace std;
int n;
int a[10005]={};
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int sum=0; 
	for(int i=1;i<=n;i++){
		if(a[i+1]==a[i]+1){
			sum++;
		}
		
	}
	cout<<sum+n;
	
	
	
	
	return 0;
}
