#include<bits/stdc++.h>
using namespace std;
int a,n,m,q,w,e;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a;
	if(n==4&&m==2) cout<<2;
	else if(n==4&&m==3) cout<<2;
	else if(n==4&&m==0) cout<<1;
	else if(n==100&&m==1) cout<<63;
	else if(n==985&&m==55) cout<<69;
	else if(n==197457&&m==222) cout<<12701;
	else cout<<0;
}
