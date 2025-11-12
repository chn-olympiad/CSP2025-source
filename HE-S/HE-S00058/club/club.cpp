#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][4],ch[N],bch[4],ans,b[N],val[N];
int check(int x){
	int y=ch[x],minn=1000000;
	for(int i=1;i<=3;i++) if(i!=y) 
		minn=min(minn,a[x][y]-a[x][i]);
	return minn;
}
bool cmp(int a,int b){return val[a]<val[b];}
int fh(int p,int num){
	int cnt=0,res=0;
	for(int i=1;i<=n;i++) if(ch[i]==p) 
		b[++cnt]=i,val[i]=check(i);
	sort(b+1,b+1+cnt,cmp);
	for(int i=1;i<=num;i++) res+=val[b[i]];
	return res;
}
int solve(){
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
	for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) if(a[i][j]>=a[i][ch[i]]) ch[i]=j;
	for(int i=1;i<=n;i++) bch[ch[i]]++,ans+=a[i][ch[i]];
	for(int i=1;i<=3;i++) if(bch[i]>n/2){ans-=fh(i,bch[i]-n/2);break;}
	return ans;
}
void clear(){
	memset(b,0,sizeof(b));memset(ch,0,sizeof(ch));
	memset(bch,0,sizeof(bch));memset(val,0,sizeof(val));ans=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) clear(),cout<<solve()<<'\n';
	return 0;
}
