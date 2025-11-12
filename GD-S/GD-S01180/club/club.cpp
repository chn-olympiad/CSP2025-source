#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
inline int in() {
	int k=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&& c<='9') {
		k=k*10+c-'0';
		c=getchar();
	}
	return f*k;
}
struct node {
	int z,w;
};
const int IN=20005;
const int N=1e5+5;
node a[N],b[N],c[N];
bool st[N];
bool cmp(node a,node b) {
	return a.z<b.z;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=in();
	while(t--) {
		int n=in(),ashu=0,bshu=0,cshu=0;
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		memset(st,false,sizeof st);
		int sum=0;
		for(int i=1; i<=n; i++) {
			a[i].z=in(),b[i].z=in(),c[i].z=in();
			a[i].w=b[i].w=c[i].w=i;
			int maxn=max(a[i].z,max(b[i].z,c[i].z));
			if(maxn==a[i].z) {
				b[i].z=b[i].z-a[i].z;
				c[i].z=c[i].z-a[i].z;
				ashu++;
				sum+=a[i].z;
			} else if(maxn==b[i].z) {
				sum+=b[i].z;
				a[i].z=a[i].z-b[i].z;
				c[i].z=c[i].z-b[i].z;
				bshu++;
			}else{
			if(maxn==c[i].z) {
				sum+=c[i].z;
				b[i].z=b[i].z-c[i].z;
				a[i].z=a[i].z-c[i].z;
				cshu++;
			}}
		}
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		sort(a+1,a+n+1,cmp);
		int lia=n/2-ashu,lib=n/2-bshu,lic=n/2-cshu;
		if(ashu>n/2) {
			int chao=ashu-n/2-1;
			int i=1,j=1;
			while(chao--) {
				while(st[b[i].w]) i++;
				while(st[c[i].w]) j++;
				int man=min(b[i].z,c[j].z);
				if(man==b[i].z&&chao>0) {
					sum+=b[i].z;
					i++;
					st[b[i].w]=true;
				} else {
					sum+=c[j].z;
					j++;
					st[c[i].w]=true;
				}
			}
		}
		if(bshu>n/2) {
			int chao=bshu-n/2-1;
			int i=1,j=1;
			while(chao--) {
				while(st[a[i].w]) i++;
				while(st[c[i].w]) j++;
				int man=min(a[i].z,c[j].z);
				if(man==a[i].z&&chao>0) {
					sum+=a[i].z;
					i++;
					st[a[i].w]=true;
				} else {
					sum+=c[j].z;
					j++;
					st[c[i].w]=true;
				}
			}
		}
		if(cshu>n/2) {
			int chao=cshu-n/2-1;
			int i=1,j=1;
			while(chao--) {
				while(st[a[i].w]) i++;
				while(st[b[i].w]) j++;
				int man=min(a[i].z,b[j].z);
				if(man==a[i].z&&chao>0) {
					sum+=a[i].z;
					i++;
					st[a[i].w]=true;
				} else {
					sum+=b[j].z;
					j++;
					st[b[i].w]=true;
				}
			}
		}
		cout << sum << "\n";
	}
//	不理解为什么思路都是对的，打了100多行，却是错的答案，
//	并且复杂度也是在O(NlogN)左右，却过不了
//	第二个样例，真的是人么？ 
	return 0;
}
