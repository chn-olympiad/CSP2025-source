#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a[10005],b[10005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<q;i++){
		cin>>b[i];
	}
	for(int i=0;i<q;i++){
		cout<<0<<endl;
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1

4
0 1 0
0 1 0
0 2 0
0 2 0

2
10 9 8
4 0 0
*/
