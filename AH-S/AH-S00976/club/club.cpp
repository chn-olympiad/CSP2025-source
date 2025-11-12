#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
int T,n,a[N],b[N],c[N],dyb[N],dyc[N];
struct Node{
	int z;
	bool sfb;
}p[N];
bool ncmp(Node a,Node b){
	return a.z>b.z;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		int ans=0;
		n=read();
		bool pb=true,pc=true;
		for(int i=1;i<=n;i++){
			a[i]=read();
			b[i]=read();
			c[i]=read();
			if(b[i]) pb=false;
			if(c[i]) pc=false;
			if(b[i]>=c[i]){
				p[i].z=b[i];
				p[i].sfb=true;
			}else{
				p[i].z=c[i];
				p[i].sfb=false;
			}
			ans+=a[i];
		}
		if(pb&&pc){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[i];
		}else if(pc){
			int ch[N];
			for(int i=1;i<=n;i++) ch[i]=b[i]-a[i];
			for(int i=1;i<=n;i++) ans+=a[i];
			sort(ch+1,ch+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=ch[i];
		}else{
			sort(p+1,p+n+1,ncmp);
			int ap=0,idb=0,idc=0;
			for(int i=1;i<=n;i++){
				if(ap<n/2||p[i].z>a[i]){
					ans+=p[i].z-a[i];
					ap++;
					if(p[i].sfb) dyb[++idb]=c[i]-b[i];
					else dyc[++idc]=b[i]-c[i];
				}
			}
			if(idb>n/2){
				sort(dyb+1,dyb+idb+1,cmp);
				idb-=n/2;
				for(int i=1;i<=idb;i++) ans+=dyb[i];
			}else if(idc>n/2){
				sort(dyc+1,dyc+idc+1,cmp);
				idc-=n/2;
				for(int i=1;i<=idc;i++) ans+=dyc[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
