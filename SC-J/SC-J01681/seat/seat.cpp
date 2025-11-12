#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return s*f;
}
const int N=205;
int n,m;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++) a[i]=read();
	int x=a[1];
	sort(a+1,a+n*m+1);
	int pos=lower_bound(a+1,a+n*m+1,x)-a;
	pos=n*m-pos+1;
	int li=pos/n;
	int ri=pos%n;
//	cout<<li<<' '<<ri<<'\n';
	if(ri!=0) li++;
	else ri=n;
	if(li&1) printf("%d %d",li,ri);
	else printf("%d %d",li,n-ri+1);
	return 0;
}
