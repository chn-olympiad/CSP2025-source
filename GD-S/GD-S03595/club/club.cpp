#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int maxn=1e5+10;
int n;
struct pp{
	int x,y;
};
bool cmpcmp(pp one,pp two){
	return one.x>two.x;
}
struct p{
	int x[4],y[4],now;
	pp aa[4];
}a[maxn];
bool cmp(p xx,p yy){
	for(int i=0;;i++){
		if(xx.now+i>=3)return 0;
		if(xx.x[xx.y[xx.now+i]]-xx.x[xx.y[xx.now+i+1]]==yy.x[yy.y[yy.now+i]]-yy.x[yy.y[yy.now+i+1]])continue;
		return xx.x[xx.y[xx.now+i]]-xx.x[xx.y[xx.now+i+1]]<yy.x[yy.y[yy.now+i]-yy.x[yy.y[yy.now+i+1]]];
	}
}
struct qu{
	p x[maxn];
	int w;
	void in(p num){
		x[++w]=num;
		int t=w;
		while(t>1&&cmp(x[t],x[t/2])){
			swap(x[t],x[t/2]);
			t/=2;
		}
	}
	p out(){
		p tmp=x[1];
		int t=1;
		while(t<=w){
			if(cmp(x[t*2],x[t*2+1])){
				swap(x[t*2],x[t]);
				t=t*2;
			}else{
				swap(x[t*2+1],x[t]);
				t=t*2+1;
			}
		}
		w--;
		return tmp;
	}
}q[4];
void put(p x,int t){
	for(;;){
		if(q[t].w==n/2){
			p tmp=q[t].out();
			if(cmp(tmp,x)){
				q[t].x[1]=x;
				tmp.now++;
				put(tmp,tmp.y[tmp.now]);
				break;
			}
			x.now++;
		}else{
			q[t].in(x);
			break;
		}
	}
}
void solve1(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i].aa[j].x;
			a[i].aa[j].y=j;
		}
		a[i].now=1;
		sort(a[i].aa+1,a[i].aa+4,cmpcmp);
		for(int j=1;j<=n;j++){
			a[i].x[j]=a[i].aa[j].x;
			a[i].y[j]=a[i].aa[j].y;
		}
	}
	for(int i=1;i<=n;i++){
		put(a[i],a[i].y[a[i].now]);
	}
	for(int i=1;i<=3;i++){
		cout<<i<<":";
		while(q[i].w){
			p tmp=q[i].out();
			cout<<tmp.x[tmp.y[tmp.now]]<<" ";
		}
		cout<<"\n";
	}
	/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
}
void solve(){
	if(1)solve1();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
