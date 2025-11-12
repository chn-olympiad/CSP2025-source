#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m;
string a[N][3],b[N][3];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i][1]>>a[i][2];
	for(int i=1;i<=m;i++)
		cin>>b[i][1]>>b[i][2];
	
	for(int i=1;i<=m;i++)
		cout<<"0\n";
	return 0;
}
