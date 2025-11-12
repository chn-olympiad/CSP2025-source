#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long a[500005],s[500005],vis[2000000],cn;
struct o{
	int l,r;
}b[500005];
bool cmd(o x,o y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}vis[s[n]]=n;
	for(int i=n-1;i>=0;i--){
		if(vis[(k^s[i])]){
			b[++cn].l=i+1;
			b[cn].r=vis[(k^s[i])];
		}vis[s[i]]=i;
	}sort(b+1,b+cn+1,cmd);
	int rr=0;
	for(int i=1;i<=cn;i++){
		if(b[i].l>rr){
			ans++;
			rr=b[i].r;
		}
	}cout<<ans;
	return 0;
}
