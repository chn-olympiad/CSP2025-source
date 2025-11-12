#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+50;
int t;
int n;
ll sum=0;
ll a[N][5],cnt[5],s[N][5],f[N][5];
struct node{
	int bm,d;
}e[5];
struct edge{
	int ch,cy;
}p[N];
bool cmp(node x,node y){
	return x.d>y.d;
}
bool cmp1(edge x,edge y){
	return x.ch<y.ch;
}
void solve(){
	cin>>n;
	sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=3;i++) cnt[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			e[j].d=a[i][j];
			e[j].bm=j;
		} 
		sort(e+1,e+4,cmp);
		for(int j=1;j<=3;j++){
			s[i][j]=e[j].d;
			f[i][j]=e[j].bm;
		}
		sum+=s[i][1];
		cnt[f[i][1]]++;
	}
	if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
		cout<<sum<<'\n';
		return;
	}
	int g;
	for(int i=1;i<=3;i++){
		if(cnt[i]>n/2) g=i;
	}
	int op=0;
	for(int i=1;i<=n;i++){
		if(f[i][1]==g){
			p[++op].ch=s[i][1]-s[i][2];
			p[op].cy=i;
		}
	}
	sort(p+1,p+1+op,cmp1);
	for(int i=1;i<=cnt[g]-(n/2);i++){
		cnt[f[p[i].cy][2]]++;
		sum-=p[i].ch;
	}
	cout<<sum<<'\n';
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

