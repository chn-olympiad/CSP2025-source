#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],k,ct;
unordered_map<int,int> mp;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]=a[i-1]^a[i];
	int ed=0;
	for(int i=1;i<=n;i++){
		int p=mp[a[i]^k];
		mp[a[i]]=i;
		if(!p&&((a[i]^k)!=0))continue;
		if(!ed||p>=ed){
			ct++;
			ed=i;
		}
	}
	cout<<ct;
}