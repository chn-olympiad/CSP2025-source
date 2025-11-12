#include <bits/stdc++.h>
using namespace std;
int sum(int n){
	if(n==2) return 2;
	else return n*sum(n-1);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a[n][2]={};
	for(int i=0;i<n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	string t[q][2]={};
	for(int i=0;i<q;i++){
		cin>>t[i][0]>>t[i][1];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
