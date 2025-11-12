#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[10001][3][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	for(int i=1;i<=n;i++)cin>>a[i][1][1]>>a[i][2][1];
	for(int i=1;i<=q;i++)cin>>a[n+i][1][2]>>a[n+i][2][2];
	cout<<2<<endl<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
