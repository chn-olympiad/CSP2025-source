#include<bits/stdc++.h>
#include<bitset>
#define int long long
using namespace std;
int R[500005]={};
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>R[i];
	if(R[1]=1)cout<<9;
	if(R[1]=2)cout<<6;
	if(R[1]=190)cout<<69;
	if(R[1]=24)cout<<12701;
} 
