#include<bits/stdc++.h>
using namespace std;
struct we{
	int l,r,w;
}a[10000005];
int b[1000015];
int find(int x){
	if(x==b[x])return x;
	return b[x]=find(b[x]);
}
int gets(int l,int r){
	l=find(l),r=find(r);
	if(l==r)return 0;
	if(l>r)swap(l,r);
	b[r]=l;
	return 1;
}
bool cmp(we x,we y){
	return x.w<y.w;
}
int n,m,k;
int read(){
	char ch=getchar();
	if(ch<'0'||ch>'9'){
		ch=getchar();
	}
	int p=0;
	while(ch>='0'&&ch<='9'){
		p=p*10+(ch-'0');
		ch=getchar();
	}
	return p;
}
int p[10015],cp[10005],cp2[10005];
int tmp[10005];
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int l,r,w;
		l=read(),r=read(),w=read();
		a[i]=we({l,r,w});
	}
	bool kp=1;
    for(int i=1;i<=k;i++){
    	cp[i]=read();
    	if(cp[i])kp=0;
    	for(int j=1;j<=n;j++)p[j]=read();
    	if(kp){
    	int pk=0;
    	for(int j=1;j<=n;j++)
    	if(p[j]==0)pk=j;
        if(pk)for(int j=1;j<=n;j++)
        a[++m].l=pk,a[m].r=j,a[m].w=p[j];
        else kp=0;
		}
	    if(kp==0){
	      ans+=cp[i];
	      for(int j=1;j<=n;j++)
	      a[++m].l=n+i,a[m].r=j,a[m].w=p[j];
		}
	}	
	for(int i=1;i<=n+k+1;i++)b[i]=i;
	sort(a+1,a+m+1,cmp);
	int list=0,i=1;
	while(list<n-1){
		if(gets(a[i].l,a[i].r)){
			if(a[i].l>n&&cp2[a[i].l]==0)cp2[a[i].l]=a[i].w;
			else if(a[i].l>n)list++,tmp[a[i].l]=1;
			else list++;
	    	ans+=a[i].w;
		}
		i++;
	}
	for(i=n+1;i<=n+k;i++)
	 if(b[i]==i||tmp[i]==0)ans-=cp[i-n];
	cout<<ans;
	return 0;
}
