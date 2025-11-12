#include<bits/stdc++.h>
using namespace std;
int n,k,x,f[1<<20],lst,s,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>k;
	memset(f,-1,sizeof f);
	f[0]=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		s^=x;
		if(f[s^k]>=lst)lst=i,ans++;
		f[s]=i;
	}
	cout<<ans;
}
