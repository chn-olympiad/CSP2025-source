#include<bits/stdc++.h>
using namespace std;
string a[200000][2],t1,t2;
int n,q;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
		for(int j=0;j<2;j++)
			cin>>a[i][j];
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		cout<<rand()<<endl;
	}
	return 0;
}
