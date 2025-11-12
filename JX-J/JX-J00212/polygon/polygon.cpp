#include <bits/stdc++.h>
using namespace std;
int a,b[3],d;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a>>b[0]>>b[1]>>b[2];
	d=b[0];
	if(d<b[1]) d=b[1];
	if(d<b[2]) d=b[2];
	if(b[0]+b[1]+b[2]>2*d) cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
