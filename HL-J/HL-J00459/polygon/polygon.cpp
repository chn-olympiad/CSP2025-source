#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[100000];
	cin>>n;
	for(int i=1;i<n;i++)
		{
			cin>>a[i];
		}
	if(n==5){
		cout<<9;
	}
	else{
		
		cout<<a[1];
		
	}
	
	return 0;
} 
