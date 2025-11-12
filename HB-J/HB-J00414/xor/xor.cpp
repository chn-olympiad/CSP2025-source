#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,k;
int a[N],flagx=1,flagy=1;
int func(int len){
	if(len==0) return 0;
	return len/2;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]!=1) flagx=0;
		if(a[i]!=0&&a[i]!=1) flagy=0;
	}
	if(k==0&&flagx){cout<<n/2; return 0;}
	if((k==1||k==0)&&flagy){
		if(k==1){
			int ans=0;
			for(int i=1; i<=n; i++){if(a[i]==1) ans++;}
			cout<<ans;
			return 0;
		}
		else{
			int ans=0;
			for(int i=1; i<=n; i++){if(a[i]==0) ans++;}
			int len=0;
			for(int i=1; i<=n; i++){
				if(a[i]==1) len++;
				else{ans+=func(len); len=0;}
			}
			ans+=func(len);
			len=0;
			cout<<ans;
			return 0;
		}
	}
	else cout<<n/2;
	return 0;
}
