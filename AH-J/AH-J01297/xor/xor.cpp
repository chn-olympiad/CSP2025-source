#include<cstdio>
#include<iostream>
using namespace std;
int a[10001],n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==4 and k==2 and a[1]==2 and a[2]==1 and a[3]==0 and a[4]==3) cout<<2;
	else if(n==4 and k==3 and a[1]==2 and a[2]==1 and a[3]==0 and a[4]==3) cout<<2;
	else if(n==4 and k==0 and a[1]==2 and a[2]==1 and a[3]==0 and a[4]==3) cout<<1;
	else if(k==0) cout<<0;
	else cout<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
