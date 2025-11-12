/*
	Name: xor 
	Copyright: +ERABY+E CONNEC+10N
	Author: FJ-J02334
	Date: 01/11/25 10:59
	Description: SP Lv.?
*/
#include<bits/stdc++.h>
using namespace std;
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
int n,k,a[500005],sum[500005],ans;
signed main(){
	fre("xor");
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],sum[i]=sum[i-1]^a[i];
	if(k==1){
		int cnt=0;
		for(int i=1;i<=n;i++)if(a[i]==1)cnt++;
		cout<<cnt;exit(0);}
	for(int i=1,t=0,lt=0;i<=n;i++){
		for(int j=lt+1;j<=i;j++)
			if((sum[i]^sum[j-1])==k){   
				lt=i;
//				cout<<j<<" "<<i<<"\n";
				ans++; break;}
	}
	cout<<ans;
	return 0;}
/*
CSP2025-J2 RP+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
CSP2025-J2 RP+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
CSP2025-J2 RP+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
CSP2025-J2 RP+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
CSP2025-J2 RP+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
CSP2025-J2 RP+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
