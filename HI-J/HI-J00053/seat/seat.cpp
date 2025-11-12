#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	int n,m;
	cin>>n>>m;
	int f[n*m];
	for(int i=0;i<n*m;i++){
		cin>>f[i];
	}
	if(n<=1&&m<=1){
		cout<<m<<' '<<n;
		return 0;
	}
	
	return 0;
}
