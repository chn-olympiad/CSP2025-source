/*#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[10005];
int find(int gg){
	int kk=gg;
	while(kk!=fa[kk]){
		kk=fa[kk]=fa[fa[kk]];
	}
	return kk;
}
struct node{
	int l,r;
	long long s;
	bool friend operator<(node q,node p){
	    return q.s<p.s;
	}
};
vector<node>q;
long long g[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int a,b;
		long long c;
		scanf("%d%d%lld",&a,&b,&c);
		q.push_back((node){a,b,c});
	}
	long long mq=0,ans=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	int sn=-1;
	if(k==0){
		sort(q.begin(),q.end());
		while(1){
		    if(mq==n-1) break;
	    	sn++;
	    	node up=q[sn];
	    	int sx=find(up.l),sy=find(up.r);
	    	if(sx==sy) continue;
	    	fa[sx]=fa[sy];
	    	ans+=up.s;
	    	mq++;
	    }
	    cout<<ans<<endl;
	    return 0;
	}
	for(int i=1;i<=k;i++){
		int u;
		scanf("%d",&u);
		for(int j=1;j<=n;j++){
			scanf("%lld",&g[j]);
		}
		for(int j=1;j<=n;j++){
			for(int k=i+1;k<=n;k++){
				q.push_back((node){j,k,g[j]+g[k]});
			}
		}
	}
	sort(q.begin(),q.end());
	
	while(1){
		if(mq==n-1) break;
		sn++;
		node up=q[sn];
		int sx=find(up.l),sy=find(up.r);
		if(sx==sy) continue;
		fa[sx]=fa[sy];
		ans+=up.s;
		mq++;
	}
	cout<<ans<<endl;
	return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
inline long long read(){
    long long sum=0;
	while(1){
		char a=getchar();
		if(a>='0'&&a<='9'){
			sum=(sum*10+a-'0');
		}
		else return sum;
	}
	return sum;
}
int n,m,k;
int fa[10005];
int find(int gg){
	int kk=gg;
	while(kk!=fa[kk]){
		kk=fa[kk]=fa[fa[kk]];
	}
	return kk;
}
struct node{
	int l,r;
	long long s;
	bool friend operator<(node q,node p){
	    return q.s>p.s;
	}
};
priority_queue<node>q;
long long g[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//scanf("%d%d%d",&n,&m,&k);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++){
		int a,b;
		long long c;
		//scanf("%d%d%lld",&a,&b,&c);
		a=read();
		b=read();
		c=read();
		q.push((node){a,b,c});
	}
	long long mq=0,ans=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	int sn=-1;
	if(k==0){
		while(mq!=n-1){
	    	node up=q.top();
	    	q.pop();
	    	int sx=find(up.l),sy=find(up.r);
	    	if(sx==sy) continue;
	    	fa[sx]=fa[sy];
	    	ans+=up.s;
	    	mq++;
	    }
	    cout<<ans<<endl;
	    return 0;
	}
	for(int i=1;i<=k;i++){
		int u;
		//scanf("%d",&u);
		u=read(); 
		for(int j=1;j<=n;j++){
			//scanf("%lld",&g[j]);
			g[j]=read();
		}
		for(int j=1;j<=n;j++){
			for(int k=i+1;k<=n;k++){
				q.push((node){j,k,g[j]+g[k]});
			}
		}
	}
	while(mq!=n-1){
		node up=q.top();
		q.pop();
		int sx=find(up.l),sy=find(up.r);
		if(sx==sy) continue;
		fa[sx]=fa[sy];
		ans+=up.s;
		mq++;
	}
	cout<<ans<<endl;
	return 0;
}

