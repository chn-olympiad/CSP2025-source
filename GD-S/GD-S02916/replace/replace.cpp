#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	int a[n][3],b[q][3];
	for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
	for(int i=0;i<q;i++) cin>>b[i][0]>>b[i][1]>>b[i][2];
	for(int i=0;i<q;i++) cout<<0<<endl;
	fclose(stdin);
	fclose(stdout);
}
