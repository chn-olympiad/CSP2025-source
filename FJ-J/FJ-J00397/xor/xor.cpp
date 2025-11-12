#include <bits/stdc++.h>
using namespace std;
#define rt return
typedef long long ll;
const int N=500100;
struct xd{
	int l,r;
	bool operator<(const xd A){
		if(r==A.r){
			rt l>A.l;
		}rt r<A.r;
	}
}v[N];
int n,k,a[N],s[N],l=0;
map<int,int> mp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),s[i]=s[i-1]^a[i];
	mp[0]=0;
	for(int i=1;i<=n;i++){
		if(mp[k^s[i]]||((k^s[i])==0)){ 
			v[++l].l=mp[k^s[i]]+1,v[l].r=i;
			if(v[l].l==0) v[l].l=1;
		}mp[s[i]]=i;
	}
	sort(v+1,v+l+1); 
	int ans=0,p;
	if(l>=1){
		ans=1,p=v[1].r;
	}for(int i=2;i<=l;i++){
		if(v[i].l>p){
			ans++,p=v[i].r;
		}
	}printf("%d\n",ans);
	rt 0;	
} 
