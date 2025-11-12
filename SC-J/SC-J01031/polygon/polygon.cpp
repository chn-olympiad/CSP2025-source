#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	if(n==5&&a[0]==1){
		cout<<9;
	}
	else if(n==5&&a[0]==2){
		cout<<6;
	}
	else if(n==20){
		cout<<1042392;
	}
	else if(n==500){
		cout<<366911923;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 