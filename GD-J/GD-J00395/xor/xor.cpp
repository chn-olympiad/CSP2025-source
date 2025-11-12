#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	long long n,k,ans=0,cnt=-1;
	cin>>n>>k;
	int a[n]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			cnt=-1;
			ans++;
			continue;}
		if(cnt<0)cnt=a[i];
		else if(cnt==k)cnt=-1,ans++;
		else cnt=(cnt^a[i]);
		if(cnt==k)cnt=-1,ans++;}
	cout<<ans;
	return 0;}
