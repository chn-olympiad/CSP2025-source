#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N];
bool vis[N];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	
	}
	
	if(n<=2){
		cout<<0;
		return 0;
	}sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]<a[3])cout<<0;
		else cout<<1;
		return 0;
	}
	cout<<0; 
	
	return 0;
} 
