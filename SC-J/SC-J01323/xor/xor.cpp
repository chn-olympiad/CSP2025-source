#include<bits/stdc++.h>
using namespace std;
int read(){
	char c=getchar();int x=0,g=1;
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') g=-1,c=getchar();
	while(c>='0' && c<='9'){
		x=(x*10)+c-'0';
		c=getchar();
	}
	return x*g;
}
int n,k,a[5000006],now,ans,sum[5000006];
map<int,int> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++){
		int b=read();
		a[i]=a[i-1]^b;
	}
	mp[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]=k^a[i];
		if(mp.find(sum[i])!=mp.end() && mp[sum[i]]>=now){
			ans++;now=i;
		}
		mp[a[i]]=i;
	}
	cout<<ans;
	return 0;
}