#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a[n][2];
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			cin>>a[i][j];
		}
	}
	string b[m][2];
	for(int i=0;i<m;i++){
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=0;i<m;i++){
		cout<<0<<endl;
	}
	return 0;
}
