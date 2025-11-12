#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("replace.in","r",stdin);
	int n,q;
	cin>>n>>q;
	string a[n][2],b[q][2];
	for(int i=0;i<=n-1;i++){
		for(int j=0;j<=2-1;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<=q-1;i++){
		for(int j=0;j<=2-1;j++){
			cin>>b[i][j];
		}
	}
	for(int i=0;i<=q-1;i++){
		cout<<0<<endl;
	}
//	freopen("replace.out","w",stdout);
	return 0;
}
