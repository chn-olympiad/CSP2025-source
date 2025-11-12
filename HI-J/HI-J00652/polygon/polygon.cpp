#include <bits/stdc++.h> 
using namespace std;

int main(){
	//feropen(".in","r",stdin);
	//feropen(".out","w",stdout);
	int n,a[5500],b=0,c,d;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		c=max(a[i],a[i+1]);
		b=a[i]+b;	
	}
	for(int i=0;i<n;i++){
		if (b>c*2){
			d++;
		}		
	}
	cout<<d;
	
	return 0;
}
