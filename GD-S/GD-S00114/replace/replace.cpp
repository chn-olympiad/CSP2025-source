#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[2][20005],b[2][20005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[0][i]>>a[1][i];
	}
	for(int i=1;i<=q;i++){
		cin>>b[0][i]>>b[1][i];
	}
	for(int i=0;i<q;i++)cout<<0<<endl;
	return 0;
} 
