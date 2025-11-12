#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
using ll=long long;
int t;
int st1[N],st2[N],st3[N],cnt[10];
bool f;
struct E{
	int a,b,c;
	int mx,mi,d,e;
}e[N];
int c1(E e1,E e2){
	return e1.a>e2.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(st1,0,sizeof(st1));
		memset(st2,0,sizeof(st2));
		memset(st3,0,sizeof(st3));
		memset(cnt,0,sizeof(cnt));
		bool A=0;
		int n;
		ll ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>e[i].a>>e[i].b>>e[i].c;
			if(e[i].b!=0||e[i].c!=0) A=1;
		}
		if(!A){
			sort(e+1,e+n+1,c1);
			for(int i=1;i<=n/2;i++) ans+=e[i].a;
		}
		cout<<ans;
	}
	return 0;
}
