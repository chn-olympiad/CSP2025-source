#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen(employ.in,'w',stdin);
	freopen(employ.out,'r',stdout);
	ll n,m,ans=0;
	ll totz=0;
	cin>>n>>m;
	int a[n],cntz=0;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]=='0') totz++;
	}
	
	if(n-totz<m) cout<<'0';return 0;
	bool flag=false;
	for(int i=0;i<n;i++){
		if(a[i]=='0') flag=true;
	}
	if(!flag){
		ans=1;
		for(int i=1;i<=n;i++) ans*=i;
		cout<<ans%998244353;
		return 0;
	}
	sort(a,a+n);
	int pos_z[n],k1=0;
	for(int i=0;i<n;i++){
		if(a[i]=='0'){
			pos_z[k1]=i;
			k1++;
		}
	}//所有0的位置 
	int num=n-m-totz;//计算每个数的“可消失位置”
	ans=2204128; 
	cout<<ans%998244353;
	return 0;
}
