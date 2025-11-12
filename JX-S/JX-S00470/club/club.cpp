#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int SZ=1e5+3;

int t,n,siz[4],be[SZ],ans;
struct node{
	int a[4];
}p[SZ];

ll read(){
	ll res=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=(res<<3)+(res<<1)+(c-'0');
		c=getchar();
	}
	return res*f;
}
void change(int x){
	priority_queue<int,vector<int>,greater<int>> Q;
	for(int i=1;i<=n;i++){
		if(be[i]==x){
			if(x==1) Q.push(min(p[i].a[1]-p[i].a[2],p[i].a[1]-p[i].a[3])); 
			else if(x==2) Q.push(min(p[i].a[2]-p[i].a[1],p[i].a[2]-p[i].a[3])); 
			else Q.push(min(p[i].a[3]-p[i].a[1],p[i].a[3]-p[i].a[2])); 
		}
	}
	while(siz[x]>n/2){
		siz[x]--;
		ans-=Q.top();
		Q.pop();
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		siz[1]=siz[2]=siz[3]=0;ans=0;
		memset(be,0,sizeof(be));
		n=read();
		for(int i=1;i<=n;i++){
			p[i].a[1]=read();
			p[i].a[2]=read();
			p[i].a[3]=read();
			if(p[i].a[1]>=p[i].a[2]&&p[i].a[1]>=p[i].a[3]) siz[1]++,be[i]=1;
			else if(p[i].a[2]>=p[i].a[1]&&p[i].a[2]>=p[i].a[3]) siz[2]++,be[i]=2;
			else if(p[i].a[3]>=p[i].a[1]&&p[i].a[3]>=p[i].a[2]) siz[3]++,be[i]=3;
			ans+=max(p[i].a[1],max(p[i].a[2],p[i].a[3]));
		}
		if(siz[1]>n/2) change(1);
		else if(siz[2]>n/2) change(2);
		else if(siz[3]>n/2) change(3);
		printf("%d\n",ans);
	}
	return 0;
}
