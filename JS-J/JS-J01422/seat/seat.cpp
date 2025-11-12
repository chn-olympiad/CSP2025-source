#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int a=0;char c;bool f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=0;
	do{a=a*10+(c^48);}while(isdigit(c=getchar()));
	return f?a:-a;
}
int n,m;
int a[110];
int id[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++)a[i]=read(),id[i]=i;
	sort(id+1,id+n*m+1,[](int i,int j){return a[i]>a[j];});
	int id1;
	for(int i=1;i<=n*m;i++)if(id[i]==1)id1=i;
	int c=(id1+n-1)/n,r=c&1?(id1-1)%n+1:n-(id1-1)%n;
	printf("%d %d\n",c,r);
	return 0;
}
