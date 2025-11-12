#include<bits/stdc++.h>
using namespace std;
int p[2000001],n,k,x[500001],a[500001],cnt,ans;
struct st{
	int l,r;
}d[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],x[i]=x[i-1]^a[i];
	memset(p,-1,sizeof(p));
	p[0]=0;
	for(int i=1;i<=n;i++){if(p[x[i]^k]>=0)cnt++,d[cnt].l=p[x[i]^k]+1,d[cnt].r=i;p[x[i]]=i;}
	for(int i=1;i<=cnt;i++){
		int j=i;
		while(d[j].l<=d[i-1].r&&j<=cnt)j++;
		if(j>cnt)break;
		i=j;
		ans++;
	}
	cout<<ans;
	return 0;
}
//0<a_i<2000000
