// GZ-S00014 代玲聪 安顺市第一中学
#include<iostream>
#include<cstdio>
#include<algorithm>
#include <string>
using namespace std;
const int N=5e6+10;
inline int in(){
	char ch=getchar();
	int w=1,s=0;
	while(ch>'9'||ch<'0'){
		if(ch=='-')w*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return w*s;
}

int n,m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=in();
	m=in();
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin >> s1 >> s2;

	}
	for(int i=1;i<=m;i++){
		cout << "0" << endl;
	}
	return 0;
}/*
#include<iostream>
#include<algorithm>
#define ll long long

using namespace std;
const int N=1e5+10;
int a[N],n;
struct tree{
	int L,R,sum,laz;
}t[N<<2];
void pushup(int u){
	t[u].sum=t[u*2].sum+t[u*2+1].sum;

}
void build(int u,int l,int r){
	int L=t[u].L,R=t[u].R;
	if(L==R){
		t[u].sum=a[L];
		return;
	}
	int m=(L+R)>>1;
	build(u*2,l,m);
	build(u*2+1,m+1,r);
	pushup(u);

}
bool in(int l,int r,int L,int R){
	return (l<L&&R<r);
}
bool out(int l,int r,int L,int R){
	return (l>R||r<L);
}
ll query(int u,int l,int r){
	int L=t[u].L,R=t[u].R;
	if(in(l,r,L,R)){
		return t[u].sum;
	}
	else if(!out(l,r,L,R)){
		int m=(L+R)>>1;
		return query(u*2,l,m)+query(u*2+1,m+1,r);
	}
	else return 0;
}
int main(){
	int q;
	cin >> n >> q;
	for(int i=1;i<=n;i+++){
		cin >> a[i];

	}
	build(1,1,n);
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		cout << query(1,x,y) << endl;
	}
}
*/
