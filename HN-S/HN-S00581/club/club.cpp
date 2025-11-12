#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=1e5+15;
int T,n;
struct node{
	int a,b,c;
}a[N],sum;
bool cmp(node a,node b){
	if(a.a==b.a){
		if(a.b==b.b)return a.c>b.c;
		return a.b>b.b;
	}
	return a.a>b.a;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
	cin>>T;
	while(T--){
		cin>>n;
		bool f1=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			sum.a+=a[i].a;
			sum.b+=a[i].b;
			sum.c+=a[i].c;
			if(a[i].b||a[i].c)f1=0;
		}
		if(f1){
			int ans=0;
			for(int i=1;i<=n;i++)ans+=a[i].a;
			cout<<ans<<endl;
			memset(a,0,sizeof(a));
			continue;
		}
		int ca=0,cb=0,cc=0,ans=0;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			int maxn=max(a[i].a,max(a[i].b,a[i].c));
			int nxta=a[i].a+max(a[i+1].c,a[i+1].b);
			int nxtb=a[i].b+max(a[i+1].a,a[i+1].c);
			int nxtc=a[i].c+max(a[i+1].a,a[i+1].b);
			if(maxn==a[i].a&&ca<n/2){
				if(i!=n){
					int maxt=nxta;
					if(cb<n/2)maxt=max(maxt,nxtb);if(cc<n/2)maxt=max(maxt,nxtc);
					if(maxt==nxta){ca++;ans+=a[i].a;}
					else if(maxt==nxtb){cb++;ans+=a[i].b;}
					else{cc++;ans+=a[i].c;}
				}
				else{
					ca++;ans+=a[i].a;
				}
			}
			else if(maxn==a[i].b&&cb<n/2){
				if(i!=n){
					int maxt=nxtb;
					if(ca<n/2)maxt=max(maxt,nxta);if(cc<n/2)maxt=max(maxt,nxtc);
					if(maxt==nxta){ca++;ans+=a[i].a;}
					else if(maxt==nxtb){cb++;ans+=a[i].b;}
					else{cc++;ans+=a[i].c;}
				}
				else{
					cb++;ans+=a[i].b;
				}
			}
			else if(maxn==a[i].c&&cc<n/2){
				if(i!=n){
					int maxt=nxtc;
					if(cb<n/2)maxt=max(maxt,nxtb);if(ca<n/2)maxt=max(maxt,nxta);
					if(maxt==nxta){ca++;ans+=a[i].a;}
					else if(maxt==nxtb){cb++;ans+=a[i].b;}
					else{cc++;ans+=a[i].c;}
				}
				else{
					cc++;ans+=a[i].c;
				}
			}
		}
		cout<<ans<<endl;
		memset(a,0,sizeof(a));
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/ 

