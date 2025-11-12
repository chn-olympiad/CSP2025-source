#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans,vis[500005];
long long ch(int st,int ed){
	long long sum=a[st];
	if(vis[st]==1) return 0;
	for(int i=st+1;i<=ed;i++){
		sum^=a[i];
		if(vis[i]==1) return 0;
	}
	return sum==k;
}
void cnm(int s,int e){
	for(int i=s;i<=e;i++){
		vis[i]=1;
	}
}
void chk(int len){
	for(int i=1;i+len-1<=n;i++){
		int l=i,r=i+len-1;
		if(ch(l,r)){
			ans++;
			cnm(l,r);
		}
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		chk(i);
	}
	cout<<ans;
	return 0;
}
