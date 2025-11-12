#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int n,c,k;
	cin>>n;
	c=n;
	int a[100];
	int b[100];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<10){
			b[i]=a[i];
		}
		else{
			c--;
		}
	}
	for(int i=0;i<c-1;i++){
		if(b[i]<b[i+1]){
			k=b[i];
			b[i]=b[i+1];
			b[i+1]=k;
		}
	}
	for(int i=0;i<c;i++){
		cout<<b[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
