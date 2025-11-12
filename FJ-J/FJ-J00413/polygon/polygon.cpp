#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int pd(int a,int b,int c){
	if(2*max(a,max(b,c))<a+b+c){
			ans++;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	int m[n];
	for(int i=1;i<=n;i++){
		cin>>m[i];
	}
	pd(m[1],m[2],m[3]);
		
	cout<<ans;
}
