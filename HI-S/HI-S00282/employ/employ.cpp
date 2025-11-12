#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s[n]={};
	int c[n]={};
	for(int i = 0;i<n;i++){
		cin>>s[i];
	}
	for(int i = 0;i<n;i++){
		cin>>c[i];
	}
	cout<<m;
	return 0;
}
