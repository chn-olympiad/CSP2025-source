#include<bits/stdc++.h>
using namespace std;
struct str{int l,r;}q[500005];
int b[500005],n,k,t,o,cnt,ans;
bool cmp(str x,str y){return x.r<y.r;}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){cin>>t;b[i]=b[i-1]^t;}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((b[j]^b[i-1])==k){q[++cnt].l=i,q[cnt].r=j;break;}
		}
	}
	sort(q+1,q+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(q[i].l>o){ans++,o=q[i].r;}
	}
	cout<<ans;
	return 0;
}
