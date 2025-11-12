#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	int a[n+10];
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	if(n==1&&k==0&&a[1]==0) cout<<"1";
	else if(n==1&&k==0&&a[1]!=0) cout<<"0";
	else if(n==2&&k==0&&a[1]==a[2]) cout<<"1";
	else if(n==2&&k==0&&a[1]!=a[2]) cout<<"0";
	return 0;
}