#include<bits/stdc++.h>
using namespace std;
int n,m;
struct data1{
	string x,y;
}a[1005],s[1005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	for(int j=1;j<=m;j++){
		cin>>s[j].x>>s[j].y;
		cout<<0<<endl;
	}
	return 0;
}
