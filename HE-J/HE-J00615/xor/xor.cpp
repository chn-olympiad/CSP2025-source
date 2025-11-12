#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=1<<22,inf=-1e9;
int n,k,a[N],sum[N],to[N],v[M],bg[M];
struct Node{
	int id,val;
	bool operator < (const Node pp)const{
		if(val==pp.val) return id<pp.id;
		return val<pp.val;
	}
}s[N];
int arsum(int l,int r){
	return sum[r]^sum[l-1];
}
int searchh(int va){
	int l=1,r=n;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(s[mid].val>=va) r=mid;
		else l=mid;
	}
	if(s[r-1].val==va) return r-1;
	if(s[r].val!=va && s[r+1].val==va) return r+1;
	return r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
		s[i].id=i,s[i].val=sum[i];
		if(!v[sum[i]]) v[sum[i]]=i;
	}
	sort(s+1,s+n+1);
	for(int i=1; i<=n; i++)
	{
		if(a[i]==k){
			to[i]=i;
			continue;
		}
		int g=sum[i-1]^k;
		int r=v[g];
		if(r==0){
			to[i]=inf;
			continue;
		}
		if(r<i){
			if(!bg[g]) bg[g]=searchh(g);
			while(s[bg[g]].val==g && s[bg[g]].id<i) bg[g]++;
			if(s[bg[g]].val!=g){
				to[i]=inf;
				continue;
			} 
			r=v[g]=s[bg[g]].id;
		}
		to[i]=r;
	}
	int cr=0,ans=0;
	for(int i=1; i<=n; i++){
		if(to[i]==inf) continue;
		if(!cr && to[i]>0){
			cr=to[i];
			ans++;
		}
		else if(to[i]<cr) cr=to[i];
		else if(i>cr){
			ans++;
			cr=to[i];
		}
	}
	printf("%d",ans);
	return 0;
}

