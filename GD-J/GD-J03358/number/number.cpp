#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=5;
    
    
    int a[100],b[100],z;

	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1)
		b[i]=a[i];
		else if(a[i]==2)
		b[i]=a[i];
		else if(a[i]==3)
		b[i]=a[i];
		else if(a[i]==4)
		b[i]=a[i];
		else if(a[i]==5)
		b[i]=a[i];
		else if(a[i]==6)
		b[i]=a[i];
		else if(a[i]==7)
		b[i]=a[i];
		else if(a[i]==8)
		b[i]=a[i];
		else if(a[i]==9)
		b[i]=a[i];
		else if(a[i]==0)
		b[i]=a[i];
	
	}
	for(int i=0;i<=n;i++){
		if(b[i]>b[i-1]){
			swap(b[i],b[i-1]);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<b[i];
	}
	
	return 0;
}  




