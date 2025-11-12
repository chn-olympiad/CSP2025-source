#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[510],ans;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	ans=n;
	for(int i=n-1;i>1;i--)
	  ans*=i;
	cout<<ans;
	return 0;
}
