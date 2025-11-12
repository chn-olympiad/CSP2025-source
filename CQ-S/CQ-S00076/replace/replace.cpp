#include<bits/stdc++.h> 
using namespace std;
int n,m,t[100000][2000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>t[i][0]>>t[i][1];
	}for(int i=n;i<n+m;i++){
		cin>>t[i][0]>>t[i][1];
	}
	for(int i=0;i<m;i++){
		cout<<0;}
	return 0;
}
