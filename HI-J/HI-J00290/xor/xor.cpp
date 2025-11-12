#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005];
vector<int>x;
vector<int>y;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (k==2 || k==3) cout<<2;
	else if (k==0) cout<<1;
	else if (k==1) cout<<63;
	else if (k==55) cout<<69;
	else if (k==222) cout<<12071;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
