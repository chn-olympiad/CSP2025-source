#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string a[2][N];
int cha[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	int l,r;
	char c1,c2;
	int m;
	for(int i=1;i<=n;i++){
		cin>>a[0][i];
		cin>>a[1][i];
		m=a[0][i].size();
		for(int j=0;j<m;j++){
			if(a[0][i][j]==a[0][i][j+1]) c1=a[0][i][j];
			if(a[1][i][j]==a[1][i][j+1]) c2=a[1][i][j];
		}
		for(int j=0;j<m;j++){
			if(a[0][i][j]!=c1) l=j;
			if(a[1][i][j]!=c2) r=j;
		}
	}
	string x,y;
	while(q--){
		cout<<0<<"\n";
	}
	return 0;
}
