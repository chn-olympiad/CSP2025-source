#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("testin","seat",stdin);
	freopen("testout","seat",stdout);
	int m,n,s,x,r,c;
	cin>>n>>m;
	int a[105];
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	s=a[1];
	for(int j=1;j<=3;j++){
		for(int i=1;i<=m*n;i++){
			if(a[i]<a[i+1]){
				swap(a[i],a[i+1]);
			}
		}
	}
	for(int i=1;i<=m*n;i++){
		if(a[i]==s){
			x=i;
		}
	}
	if(x%n==0){
		c=x/n;
	}else{
		c=x/n+1;
	}
	
	if(c%2==0){
		if(x%n==0){
			r=n;
		}else{
			r=n-x%n;
		}
	}else{
		if(x%n==0){
			r=n;
		}else{
			r=x%n;
		}	
	}
	cout<<c<<" "<<r;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
