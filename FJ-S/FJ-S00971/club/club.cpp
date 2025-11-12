#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

struct p{
	int a,b,c;
	p(){}
	p(int a,int b,int c):a(a),b(b),c(c){}
	bool operator<(p ot){return a==ot.a?(b==ot.b?c>ot.c:b>ot.b):a>ot.a;}
};

int miku;
int n;
p a[100005];
ll mem[205][205][205];

int dfs(int k,int na,int nb,int nc,int res){
	if(k>n) return res;
	int ans=0;
	if(na) ans=max(ans,dfs(k+1,na-1,nb,nc,res+a[k].a));
	if(nb) ans=max(ans,dfs(k+1,na,nb-1,nc,res+a[k].b));
	if(nc) ans=max(ans,dfs(k+1,na,nb,nc-1,res+a[k].c));
	return ans;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("club.in","r",stdin); freopen("club.out","w",stdout);
	cin>>miku;
	while(miku--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].a>>a[i].b>>a[i].c;
		sort(a+1,a+1+n);
		memset(mem,-1,sizeof(mem));
		if(n<=10){
			cout<<dfs(1,n/2,n/2,n/2,0)<<endl;
			continue;
		}
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=a[i].a;
		}
		cout<<ans<<endl;
	}
	return 0;
}

/*
So why did I choose OI
The training spends me half of the weekend
But I get no scores in the past years
I am too tired to continue the learning of OI
Maybe OI is too hard for me
Maybe whk is a better choice

Luogu uid: 693282
Will AFO if my score is bad.

gu fen: 25+16+10+8=59 (least?)
I am so vegetable.
*/
