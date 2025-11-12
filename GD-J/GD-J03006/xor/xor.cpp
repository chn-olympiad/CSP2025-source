#include<bits/stdc++.h>
using namespace std;
const int N=(1<<20)+5;
int n,k,a,b,ans,pos,p[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>k;
	memset(p,-1,sizeof p);
	p[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a;b^=a;
		if(p[b^k]>=pos){
			ans++;pos=i;
		}
		p[b]=i;
	}
	cout<<ans;
	return 0;
}
