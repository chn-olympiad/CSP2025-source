#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN=1e5+5;
template<typename T>
void cin__(T &n){
	T s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=(s<<1)+(s<<3)+(ch^48);
		ch=getchar();
	}
	n=s*f;
}
template<typename T>
void cout__(T n){
	if(n<0){
		putchar('-');
		n*=-1;
	}
	if(n>9) cout__(n/10);
	putchar(n%10^48);
}
struct poi{
	ll a,b,c;
	ll mx(){
		return max(max(a,b),c);
	}
};
int re=-1;
bool cmpbc(poi l,poi r){
	if(re==0) return max(l.b,l.c)-l.a>max(r.b,r.c)-r.a;
	else if(re==1) return max(l.a,l.c)-l.b>max(r.a,r.c)-r.b;
	else return max(l.a,l.b)-l.c>max(r.a,r.b)-r.c;
}
int n;
poi tong[3][MAXN];
int tn[3];
void solve(){
	tn[0]=tn[1]=tn[2]=0;
	cin__(n);
	for(int i=1,a,b,c;i<=n;++i){
		cin__(a),cin__(b),cin__(c);
		int lmx=max(max(a,b),c);
		if(lmx==a) tong[0][++tn[0]]={a,b,c};
		else if(lmx==b) tong[1][++tn[1]]={a,b,c};
		else tong[2][++tn[2]]={a,b,c};
	}
	int ans=0;
	re=-1;
	if(tn[0]>n/2) re=0;
	else if(tn[1]>n/2) re=1;
	else if(tn[2]>n/2) re=2;
	int resum=0;
	if(re!=-1) sort(tong[re]+1,tong[re]+tn[re]+1,cmpbc);
	if(re!=-1) resum=tn[re]-n/2;
	for(int i=0;i<=3;++i){
		for(int j=1;j<=tn[i];++j){
			if(re==i&&j<=resum){
				if(i==0) ans+=max(tong[i][j].b,tong[i][j].c);
				else if(i==1) ans+=max(tong[i][j].a,tong[i][j].c);
				else ans+=max(tong[i][j].a,tong[i][j].b);
			}
			else ans+=tong[i][j].mx();
		}
	}
	cout__(ans);putchar('\n');
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin__(T);
	while(T--) solve();
	return 0;
}
