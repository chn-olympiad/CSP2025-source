#include<bits/stdc++.h>
using namespace std;
const int P=998244353,N=5010;
int g[N],f[N][5];int ans,n,x=0;
void q(int s,int tot,int m,int l){
	bool a=true;
	for(int i=1;i<=x;i++){
		if(f[i][1]==l && f[i][2]==m && f[i][3]==tot){
			a=false;break;
		}
	}
	if(l>=3 && m+m<tot && a){
		ans++;
		ans%=P;
		cout<<3<<' '<<l<<' '<<m<<' '<<tot<<endl;
		f[++x][1]=l,f[++x][2]=m,f[++x][3]=tot;
	}
	cout<<1;
	if(s>n) return;
	cout<<2<<endl;
	q(s+1,tot,m,l);
	q(s+1,tot+g[s],max(m,g[s]),l+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&g[i]);
	}
	q(1,0,0,0);
	cout<<endl<<ans;
	return 0;
}
