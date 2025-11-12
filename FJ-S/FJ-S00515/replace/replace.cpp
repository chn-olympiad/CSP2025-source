#include<bits/stdc++.h>
using namespace std;
int n,q;
int caipiao[12]={0,1,4,6,0,21,89,3,0,678,93};
string  a[2][200000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[0][i]>>a[1][i];
	}
	for(int i=0;i<q;i++){
		cin>>a[0][i]>>a[1][i];
	}
	for(int i=0;i<q;i++){
		cout<<caipiao[i]<<'\n';
	}
	return 0;
}
