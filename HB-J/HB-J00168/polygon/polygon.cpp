#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int m[n]={};
	for(int i=0;i<n;i++){
		cin>>m[i];
	}
	cout<<min(m[0],m[1])+max(m[1],m[2]);
	return 0;
}
