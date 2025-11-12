#include<bits/stdc++.h>
using namespace std;
int a[500010],s[500010],mn[500010],t[500010];
map<int,int>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)f=1;
	}
//	if(!f&&k==1){
//		int c=0;
//		for(int i=1;i<=n;i++){
//			if(a[i]==1)c++;
//		}
//		cout<<c;
//		return 0;
//	}
//	for(int i=1;i<=n;i++){
//		if(a[i]==k){
//			s[i]=i;
//			continue;
//		}
//		int t=a[i];
//		s[i]=1e9;
//		for(int j=i+1;j<=n;j++){
//			t^=a[j];
//			if(t==k){
//				s[i]=j;
//				break;
//			}
//		}
//	}
	for(int i=1;i<=n;i++)t[i]=t[i-1]^a[i];
	for(int i=n;i>=1;i--){
		mp[t[i]]=i;
		int r=mp[t[i-1]^k];
		if(r==0)s[i]=1e9;
		else s[i]=r;
	}
	mn[n+1]=1e9;
	for(int i=n;i>=1;i--)mn[i]=min(mn[i+1],s[i]);
	int x=mn[1];
	if(x>n){
		cout<<0;
		return 0;
	}
	int c=0;
	while(1){
		c++;
		x=mn[x+1];
		if(x>n)break;
	}
	cout<<c;
	return 0;
}
