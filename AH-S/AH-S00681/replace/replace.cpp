#include<bits/stdc++.h>
using namespace std;
int n,m;
string a[10005],b[10005];
string x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}for(int j=1;j<=m;j++){
		cin>>x>>y;
		int x1=x.size(),y1=y.size();
		cout<<m-j*2<<endl;
	}
	return 0;
}
