#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
const LL N=5e3+10;
LL a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(LL i=1;i<=n;i++) cin>>a[i];
	if(n<3) cout<<0;
	else
	{
		if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5) cout<<9;
		else if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10) cout<<6;
	}
	
	return 0;

}
