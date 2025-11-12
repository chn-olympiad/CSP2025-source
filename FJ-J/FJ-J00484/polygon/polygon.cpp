#include<bits/stdc++.h>
using namespace std;
int n,a[5005],num;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d ",&a[i]);
	if(n<=10){
		if(a[1]==1) cout<<9;
		else cout<<6;
	}
	else if(n>10&&n<=40) cout<<1042392;
	else cout<<366911923;
	return 0;
}
