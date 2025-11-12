#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define pb push_back
typedef pair<int,int>pii;
typedef vector<int>vint;
typedef vector<pii>vpii;
const int mod=998244353;
void add(int&a,int b){a=(a+b>=mod)?a+b-mod:a+b;}
void mul(int&a,int b){a=(a-b<0)?a-b+mod:a-b;}

const int N=19;
int n,m;
char s[N];
int a[N];
int f[N][1<<N];
vint p[N];
int pc[1<<N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	p[0].pb(0);
	for(int i=1;i<(1<<n);i++){
		pc[i]=pc[i^(i&-i)]+1;
		p[pc[i]].pb(i);
	}
	f[0][0]=1;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			for(int j=0;j<=i;j++)
				for(int k:p[i]){
					for(int l=0;l<n;l++)
						if(!(k>>l&1)) add(f[j][k|(1<<l)],f[j][k]);
				}
		}else{
			for(int j=0;j<=i;j++)
				for(int k:p[i]){
					for(int l=0;l<n;l++)
						if(!(k>>l&1)) add(f[j+(i-j<a[l])][k|(1<<l)],f[j][k]);
				}
		}
	}
	int sum=0;
	for(int i=m;i<=n;i++)
		add(sum,f[i][(1<<n)-1]);
	cout<<sum;
	return 0;
}
/*
Ren5Jie4Di4Ling5%
*/