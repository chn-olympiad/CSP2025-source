#include<bits/stdc++.h>
using namespace std;
int f(int k,int b){
	int g;
	for(int i=1;i<=k-1;i++){
		g+=a[i];
	}
	
}
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.uot","w",stduot);
	int n,w=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		if(i>=3){
			
		w+=f(i);
	   }
	   else break;
	}
	cout<<w;
	return 0;
}
