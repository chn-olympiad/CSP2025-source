#include<bits/stdc++.h>
#define F(i,a,b) for(register int i=a;i<=b;i=-~i)
#define D(i,a,b) for(register int i=a;i>=b;i=~-i)
#define ad(k) (k=-~k)
using namespace std;const int N=5e5+1;
int n,k,a[N],ans,ans1;bool vis[N];
int main(){
	freopen("xor5.in","r",stdin),freopen("xor.out","w",stdout);
	cin>>n>>k;
	F(i,1,n)cin>>a[i];
	F(p,0,n+1){
		F(l,1,n){
			if(l+p>n)break;
			int r=l+p,x=a[l],f=0;
			F(i,l+1,r){if(vis[i]||vis[l]){f=1;break;}x^=a[i];}
			if(f==1)continue;
			if(x==k){vis[l]=vis[r]=1;ans++;}
		}
	}cout<<ans;
	return 0;
}
