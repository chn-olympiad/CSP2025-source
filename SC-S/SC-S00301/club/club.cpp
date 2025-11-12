#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int t,n,m;
bool flag1,flag2;
struct node{
	int a,b,c,id;
}cs[N];

int read(){
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}

//bool cmp(node x,node y){
//	return x.a>y.a;
//}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while (t--){
		n=read();
		flag1=0,flag2=0;
		for (int i=1;i<=n;i++){
			cs[i].a=read();
			cs[i].b=read();
			cs[i].c=read();
			cs[i].id=i;
			if (cs[i].b!=0)
				flag1=1;
			if (cs[i].c!=0)
				flag2=1;
		}
		int ans=0;
		if (n==2){
			int aa=cs[1].a;
			int bb=cs[1].b;
			int cc=cs[1].c;
			int x=cs[1].a;
			int y=cs[1].b;
			int z=cs[1].c;
			ans=aa+y;
			ans=max(ans,aa+y);
			ans=max(ans,aa+z);
			ans=max(ans,bb+x);
			ans=max(ans,bb+z);
			ans=max(ans,cc+x);
			ans=max(ans,cc+y);
		}
		else if (flag1==0&&flag2==0){
//			sort(cs+1,cs+n+1,cmp);
			for (int i=1;i<=m;i++)
				ans+=cs[i].a;
		}
		else {
			ans=0;
			for (int i=1;i<=n;i++){
				ans+=max(cs[i].a,max(cs[i].b,cs[i].c));
			}
		}
		cout <<ans<<endl;
	}
	return 0;
}
/*
18
4
13
*/