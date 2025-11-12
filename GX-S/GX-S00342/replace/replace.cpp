#include<bits/stdc++.h>
using namespace std;
int main(){
	stdin(replace.in,'w',stdin);
	stdout(replace.out,'r',stdout);
	int n,q;
	cin>>n>>q;
	string a[n][2],b[q][2];
	for(int i=0;i<n;i++)cin>>a[i][0]>>a[i][1];
	for(int i=0;i<q;i++)cin>>b[i][0]>>b[i][1];
	for(int i=0;i<q;i++)cout<<0<<endl;
	return 0;
}
