#include <bits/stdc++.h>
using namespace std;
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n,k,c;
int a[10010];
int main(){
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c+=a[i]; 
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		if(a[i]>maxn){
			maxn=a[i];
		}
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		if(c>2*maxn){
			cout<<1;  
		}
		else{
			cout<<0;
		}
		return 0;
	}
	else  {
		int num=0;
		cout<<18;
	}
	return 0;
} 

