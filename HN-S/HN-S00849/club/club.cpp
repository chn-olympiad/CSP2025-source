#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int T,n;
struct node{
	long long d1,d2,d3;
	long long dx;
	long long c1,c2,p1,p2;
}a[MAXN];
bool cmp(node x,node y){
	if(x.dx==y.dx)return x.dx;
	return x.dx>y.dx;
}
int g[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		long long ans=0;
		memset(g,0,sizeof(g));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			long long maxn=-1,maxp=-2,maxid,maxid0;
			if(a[i].d1>maxn)maxn=a[i].d1,maxid=1;
			if(a[i].d2>maxn)maxn=a[i].d2,maxid=2;
			if(a[i].d3>maxn)maxn=a[i].d3,maxid=3;
			if(a[i].d1>maxp&&maxid!=1)maxp=a[i].d1,maxid0=1;
			if(a[i].d2>maxp&&maxid!=2)maxp=a[i].d2,maxid0=2;
			if(a[i].d3>maxp&&maxid!=3)maxp=a[i].d3,maxid0=3;
			a[i].dx=maxn-maxp;
			a[i].c1=maxid;
			a[i].c2=maxid0;
			a[i].p1=maxn;
			a[i].p2=maxp;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(g[a[i].c1]>=n/2){
				ans+=a[i].p2;
				g[a[i].c2]++;
			}else{
				ans+=a[i].p1;
				g[a[i].c1]++;
			}
		}
		cout<<ans<<endl;
	}
	
	
	
	return 0;
}
