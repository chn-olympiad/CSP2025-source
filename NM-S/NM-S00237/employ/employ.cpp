#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(".in","r",stdin);
	int n,m,t,s=0;
	string a;
	cin>>n>>m;
	int c[n];
	cin>>a;
 	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
		if(c[i]>c[j]){
			t=c[i];
			c[i]=c[j];
			c[j]=c[i];
			}
		}
	}
	for(int i=0;i<n;i++){
		//if(a[i]="1")
		if(c[i]<s){
			t=c[i];
			c[i]=c[i+1];
			c[i+1]=c[i];
			s=s+1;}	
		if(a[i]=='0'){
			t=c[i];
			c[i]=c[i+1];
			c[i+1]=c[i];
			s=s+1;
			
		}
			
		
	}
	if(n-s<m){
		cout<<m;
	}	
	else{
		cout<<n-s;
		}
	freopen(".out","w",stdout);
	return 0;
}

