#include<algorithm> 
#include<iostream> 
#include<cstdio> 
#include<math.h> 
#include<string> 
#include<map> 
using namespace std;
const int N=3e6+10,M=1e3+10;
const int INF=0x3f3f3f3f;
const int MOD=998244353;
int n,m,k,a[M],f[M],cnt[M];
string s;
int q[N],top=1;
/*
void pushdown(int x){
	if((x<<1)>top)return;
	if((x<<1|1)>top){
		if(w[q[x]]>w[q[x<<1]]){
			swap(q[x],q[x<<1]);
			pushdown(x<<1);
		}
		return;
	}
	
	if(w[q[x<<1]]<w[q[x<<1|1]]){
		if(w[q[x]]>w[q[x<<1]]){
			swap(q[x],q[x<<1]);
			pushdown(x<<1);
		}
	}else{
		if(w[q[x]]>w[q[x<<1|1]]){
			swap(q[x],q[x<<1|1]);
			pushdown(x<<1|1);
		}
	}
}
void pushup(int x){
	if(x==1)return;
	if(w[q[x]]<w[q[x>>1]]){
		swap(q[x],q[x>>1]);
		pushup(x>>1);
	}
}
void qadd(int id){
	q[++top]=id;
	pushup(top);
}
void qpop(){
	q[1]=q[top];
	--top;
	pushdown(1);
}
void push(int id){
	q[++top]=id;
	pushdown(top);
}
*/
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	f[0]=0;
	for(int i=0;i<n;i++){
		f[i+1]=f[i];
		if(s[i]=='0')f[i+1]++;
		cnt[f[i+1]]++;
	}
	for(int i=1;i<=n;i++)cnt[i]+=cnt[i-1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//sort(a+1,a+n+1,cmp);
	//sort(a+1,a+m+1);
	/*for(int i=1;i<=n;i++)cout<<f[i]<<' ';cout<<'\n';
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';cout<<'\n';
	for(int i=0;i<=n;i++)cout<<cnt[i]<<' ';cout<<'\n';
	*/
	int j=1;
	long long ans=1;
	for(int i=1;i<=m;i++){
		ans*=cnt[a[i]-1]-i+1;
		ans%=MOD;
	}
//	for(int i=)
	long long anss=1;
	for(int i=1;i<=n;i++){
		anss*=i;
		anss%=MOD;
	}
	cout<<anss;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
