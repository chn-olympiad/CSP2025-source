#include <bits/stdc++.h>
using namespace std;
int a[3];
int b(int n,int m){
	cin>>n;
	for(int i=1;i>=3;i++){
		cin>>a[i];
	}
	for(int i=1;i>=3;i++){
		if(a[i]>a[i+1]){
			m=a[i];
		}
		else{
			m=a[i+1];
		}
	}
	return m;
}
int main(){
	freopen("club.in","r",stdin);	
	freopen("club.out","w",stdout);	
	int t,n,m;
	cin>>t>>n;
	for(int i=1;i>=n;i++){
		b(n,m);
		m++;
	}
	fclose("club.in",stdin);
	fclose("club.out",stdout);
	cout<<m;
	return 0;
}
