#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct Node{
	int a,b,c;
};
Node p[N];
int n;
bool cmp(Node x,Node y){
	return max(x.b,x.c)-x.a>max(y.b,y.c)-y.a;
}
void work(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i].a>>p[i].b>>p[i].c;
	int ans=0;
	int nowa=0,nowb=0,nowc=0;
	for(int i=1;i<=n;i++){
		int q=max(max(p[i].a,p[i].b),p[i].c);
		if(q==p[i].a) ans+=p[i].a,nowa++;
		else if(q==p[i].b) ans+=p[i].b,nowb++;
		else ans+=p[i].c,nowc++;
	}
	if(nowa<=n/2&&nowb<=n/2&&nowc<=n/2){
		cout<<ans<<'\n';
		return ;
	}
	if(nowb>n/2){
		for(int i=1;i<=n;i++) swap(p[i].a,p[i].b);
		swap(nowa,nowb);
	}
	else if(nowc>n/2){
		for(int i=1;i<=n;i++) swap(p[i].a,p[i].c);
		swap(nowa,nowc);
	}
	sort(p+1,p+1+n,cmp);
	for(int i=1,j=1;j<=nowa-n/2;i++){
		if(p[i].a>=max(p[i].b,p[i].c)){
			ans=ans+max(p[i].b,p[i].c)-p[i].a;
			j++;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--) work();
	return 0;
}
