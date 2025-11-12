#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
ll b[4][50010];
ll s;
struct aaa{
	ll a[4];
	int l,m;
}q[100010];

int c(aaa m){
	if(m.a[1]>=m.a[2]&&m.a[1]>=m.a[3]) return 1;
	else if(m.a[2]>=m.a[1]&&m.a[2]>=m.a[3]) return 2;
	else return 3;
}
int d(aaa w){
	if((w.a[1]>=w.a[2]&&w.a[2]>=w.a[3])||(w.a[3]>=w.a[2]&&w.a[2]>=w.a[1])&&c(w)!=2) return 2;
	else if((w.a[3]>=w.a[1]&&w.a[1]>=w.a[2])||(w.a[2]>=w.a[1]&&w.a[1]>=w.a[3])&&c(w)!=1) return 1;
	else return 3;
}
bool cmp(int a,int b){
	if(q[a].l-q[a].m>=q[b].l-q[b].m) return 1;
	else return 0;
}

void solve(){
	s=0;
	bool f=1;
	int k;
	cin>>n;
	b[1][0]=b[2][0]=b[3][0]=0;
	for(ll i=1;i<=n;i++){
		cin>>q[i].a[1]>>q[i].a[2]>>q[i].a[3];
		q[i].l=q[i].a[c(q[i])];
		q[i].m=q[i].a[d(q[i])];
		k=c(q[i]);
		b[k][0]++;
		b[k][b[k][0]]=i;
		s+=q[i].a[k];
	}
	k=0;
	if(b[1][0]>n/2) k=1;
	else if(b[2][0]>n/2) k=2;
	else if(b[3][0]>n/2) k=3;
	if(k) sort(b[k]+1,b[k]+b[k][0]+1,cmp);
	for(int i=n/2+1;i<=b[k][0];i++){
		s-=q[b[k][i]].l-q[b[k][i]].m;
	}
	cout<<s<<endl;
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
