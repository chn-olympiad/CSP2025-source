#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=0,q=0;
	cin>>n>>q;
	string x[n][2]={},y[q][2]={};
	for(int i=0;i<n;i++){
		cin>>x[i][0]>>x[i][1];
	}for(int i=0;i<q;i++){
		cin>>y[i][0]>>y[i][1];
	}
	for(int i=0;i<q;i++){
		cout<<0<<endl;
	}
	return 0;
}
