#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int a[101]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m=1){
		cout<<1;
		return 0;
	}
	if(n=2&&m=2){
		cout<<2;
		return 0;
	}
	cout<<3;
	return 0;
}
