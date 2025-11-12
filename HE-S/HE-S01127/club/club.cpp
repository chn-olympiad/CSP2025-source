#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
struct node{
	int a,b,c;
	int maxnum,k,sec;
}a[MAXN];
int cnt[MAXN];
bool cmp(node x,node y){
	return x.maxnum>y.maxnum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(cnt,0,sizeof(cnt));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>a[i].b&&a[i].a>a[i].c){
				a[i].maxnum=a[i].a;
				a[i].k=1;
				if(a[i].b>a[i].c) a[i].sec=2;
				else a[i].sec=3;
			}else if(a[i].a>a[i].b&&a[i].a>a[i].c){
				a[i].maxnum=a[i].b;
				a[i].k=2;
				if(a[i].a>a[i].c) a[i].sec=1;
				else a[i].sec=3;
			}else{
				a[i].maxnum=a[i].c;
				a[i].k=3;
				if(a[i].a>a[i].b) a[i].sec=1;
				else a[i].sec=2;
			}
		}
		sort(a+1,a+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(cnt[a[i].k]<n/2) ans+=a[i].maxnum;
			else if(cnt[a[i].sec]<n/2) {
				if(a[i].sec==1) ans+=a[i].a;
				else if(a[i].sec==2) ans+=a[i].b;
				else ans+=a[i].c;
			}
		}
		cout<<ans;
	}
	return 0;
}
