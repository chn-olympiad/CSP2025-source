#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],www=0,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int y=0,e=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		e+=a[i];
		y=max(y,a[i]);
	}
	if(2*y<e) cout<<1;
	else cout<<0;
	return 0;
	fclose(stdin);
	fclose(stdout);
}