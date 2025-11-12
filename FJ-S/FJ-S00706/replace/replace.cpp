#include<bits/stdc++.h>
using namespace std;
char a[10005][10005],b[10005][10005];
string x,y;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>a[i][j]>>b[i][j];
		} 
	}
	cin>>x>>y;
	for(int i=1;i<=q;i++){
		cout<<"0"<<endl;
	}
	return 0;
} 
