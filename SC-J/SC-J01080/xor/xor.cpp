#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5,M=3e6+5,Q=3e6;
struct node{int l,r;}b[M];
int a[N],lst[M],tot;

inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*f;
}

inline bool operator < (node x,node y){
	return x.r<y.r;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++) a[i]=(a[i-1] xor read());
	for(int i=0;i<=Q;i++) lst[i]=-1;
	for(int i=1;i<=n;i++){ 
		int nd=(k xor a[i]);
		if(nd==0) b[++tot]={1,i}; 
		if(lst[nd]!=-1) b[++tot]={lst[nd],i};
		lst[a[i]]=i+1;
	}
	sort(b+1,b+tot+1);
	int now=0,ans=0;
	for(int i=1;i<=tot;i++){
		if(b[i].l<=now && now<=b[i].r) continue;
		ans++,now=b[i].r;
	}
	cout<<ans;
	return 0;
}