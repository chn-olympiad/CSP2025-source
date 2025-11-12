#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^'0');c=getchar();}
	return x*f;
}
ll ans=0;
int q[30],c[30],p[30],n,m;
bool v[30];
string s;
bool check(){
	static int fai=0,acp=0;
	fai=0,acp=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'||c[p[i]]<=fai){
			fai++;
		}else{
			acp++;
		}
	}
	return acp>=m;
}
void dfs(int x){
	if(x>n){
		ans+=check();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;p[x]=i;
			dfs(x+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	int must_fail=0;
	for(int i=1;i<=n;i++){
		must_fail+=s[i]=='0';
		cin>>c[i];
	}
	if(must_fail>n-m){
		cout<<"0\n";
	}
	dfs(1);
	cout<<ans;
}


