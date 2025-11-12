#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+3;
struct node{
	int a,b,c,id;
}nod[maxn],as[maxn],bs[maxn],cs[maxn];
//损失越小，排越前面 
inline bool cmp1(node x,node y){return x.a-max(x.b,x.c)<y.a-max(y.b,y.c);}
inline bool cmp2(node x,node y){return x.b-max(x.a,x.c)<y.b-max(y.a,y.c);}
inline bool cmp3(node x,node y){return x.c-max(x.a,x.b)<y.c-max(y.a,y.b);}
int n,t1,t2,t3;
ll ret;
void solve(){
	cin>>n;
	t1=t2=t3=ret=0;
	for(int i=1;i<=n;i++){
		cin>>nod[i].a>>nod[i].b>>nod[i].c,nod[i].id=i;
		int mx=max({nod[i].a,nod[i].b,nod[i].c});
		if(mx==nod[i].a)as[++t1]=nod[i];
		else if(mx==nod[i].b)bs[++t2]=nod[i];
		else cs[++t3]=nod[i];
		ret+=mx;
	}
	if(t1<=n/2&&t2<=n/2&&t3<=n/2)return cout<<ret<<'\n',void();
	if(t1>n/2){
		sort(as+1,as+t1+1,cmp1);
		for(int i=1;i<=t1-n/2;i++)ret-=as[i].a-max(as[i].b,as[i].c);
		cout<<ret<<'\n';
	}
	else if(t2>n/2){
		sort(bs+1,bs+t2+1,cmp2);
		for(int i=1;i<=t2-n/2;i++)ret-=bs[i].b-max(bs[i].a,bs[i].c);
		cout<<ret<<'\n';
	}
	else{
		sort(cs+1,cs+t3+1,cmp3);
		for(int i=1;i<=t3-n/2;i++)ret-=cs[i].c-max(cs[i].a,cs[i].b);
		cout<<ret<<'\n';
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--)solve();
	return 0;
} 