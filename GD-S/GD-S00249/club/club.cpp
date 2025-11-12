#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
const int N=100005;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
} 
int t,n;
int a[N],b[N],c[N],a1[N],b1[N],c1[N]; 
int sza,szb,szc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		queue<int> q;
		priority_queue<pii> aa,bb,cc;
		sza=0; szb=0; szc=0;
		n=read();
		for(int i=1;i<=n;i++){
			a1[i]=read(); b1[i]=read(); c1[i]=read();
			if(a1[i]>=b1[i]&&b1[i]>=c1[i]){
				a[i]=a1[i]-b1[i];
				b[i]=b1[i]-c1[i];
				c[i]=c1[i];
			}
			else if(a1[i]>=c1[i]&&c1[i]>=b1[i]){
				a[i]=a1[i]-c1[i];
				c[i]=c1[i]-b1[i];
				b[i]=b1[i];
			}
			else if(b1[i]>=a1[i]&&a1[i]>=c1[i]){
				b[i]=b1[i]-a1[i];
				a[i]=a1[i]-c1[i];
				c[i]=c1[i];
			}
			else if(b1[i]>=c1[i]&&c1[i]>=a1[i]){
				b[i]=b1[i]-c1[i];
				c[i]=c1[i]-a1[i];
				a[i]=a1[i];
			}
			else if(c1[i]>=a1[i]&&a1[i]>=b1[i]){
				c[i]=c1[i]-a1[i];
				a[i]=a1[i]-b1[i];
				b[i]=b1[i];
			}
			else{
				c[i]=c1[i]-b1[i];
				b[i]=b1[i]-a1[i];
				a[i]=a1[i];
			}
			q.push(i);
		}
		while(!q.empty()){
			int i=q.front(); q.pop();
			if(a1[i]>=b1[i]&&a1[i]>=c1[i]){
				aa.push({-a[i],i});
				sza++;
				if(sza>(n>>1)){
					pii tmp=aa.top();
					aa.pop();
					q.push(tmp.se);
					a1[tmp.se]=-1;
					sza--;
				}
			}
			else if(b1[i]>=a1[i]&&b1[i]>=c1[i]){
				bb.push({-b[i],i});
				szb++;
				if(szb>(n>>1)){
					pii tmp=bb.top();
					bb.pop();
					q.push(tmp.se);
					b1[tmp.se]=-1;
					szb--;
				}
			}
			else if(c1[i]>=a1[i]&&c1[i]>=b1[i]){
				cc.push({-c[i],i});
				szc++;
				if(szc>(n>>1)){
					pii tmp=cc.top();
					cc.pop();
					q.push(tmp.se);
					c1[tmp.se]=-1;
					szc--;
				}
			}
		}
		int ans=0;
		while(!aa.empty()){
			ans+=a1[aa.top().se]; aa.pop();
		}
		while(!bb.empty()){
			ans+=b1[bb.top().se]; bb.pop();
		}
		while(!cc.empty()){
			ans+=c1[cc.top().se]; cc.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}

