#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b[m*n];
	for(int i=0;i<m*n;i++){
		cin>>b[i];
	}
	int r=b[0];	
	for(int i=0;i<m*n;i++){
		for(int j=i+1;j<m*n;j++){
			if(b[i]<b[j]){
				int mid=b[i];
				b[i]=b[j];
				b[j]=mid;
			}
		}
	}
	int ans=0;
	for(int i=0;i<m*n;i++){
		if(b[i]==r){
			ans=i;
			break;
		}
	}
	ans++;
	int c,a;
	if(ans%n==0){
		a=ans/n;
	}
	else a=ans/n+1; 
	if(a%2==0) {
		if(ans%n==0){
			c=1;
		}
		else c=n+1-ans%n;
	}
	else{
		c=ans%n;
		if(c==0){
			c+=n;
		}	
	}
	cout<<a<<' '<<c;
	fclose(stdin);fclose(stdout);
	return 0;
}
