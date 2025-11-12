#include<bits/stdc++.h>

using namespace std;

#define LL long long

const int N=1e3+6;
const LL mod=998244353;

LL T,n,m,sum,cnt,ans;
LL A[N],B[N],C[N];
bool a,b,c,d;
string s;

void check(){
	LL y=0,z=0;
	for(int i=1;i<=n;i++){
		if(A[C[i]]<=z){
			z++;
		}
		else{
			if(s[i-1]=='0')z++;
			else y++;
		}
	}
	if(y>=m)ans++;
	return ;
}

void dfs(LL x){
	if(x==n+1){
		check();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(B[i]==0){
			B[i]=x;C[x]=i;
			dfs(x+1);
			B[i]=0;C[x]=0;
		}
	}
	return ;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	a=b=c=d=1;
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cnt+=(s[i]=='1');
	}
	c=(m==1);
	d=(m==n);
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}
	ans=0;
	if(cnt<m){
		cout<<0<<endl;
	}
	else if(d){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%mod;
			if(A[i]==0)ans=0;
		}
		cout<<ans<<endl;
	}
	else if(c){
		for(int i=1;i<=n;i++){
			B[A[i]]++;
		}
		for(int i=0;i<=n;i++){
			C[i]=B[i];
			if(i>0)C[i]+=C[i-1];
		}
		sum=1;cnt=0;
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				sum=(sum*(C[i]-cnt))%mod;
				cnt++;
			}
		}
		cnt=n-cnt;
		for(int i=1;i<=cnt;i++){
			sum=(sum*i)%mod;
		}
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%mod;
		}
		ans=(ans-sum+mod)%mod;
		cout<<ans<<endl;
	}
	else if(n<=10){
		ans=0;
		dfs(1);
		cout<<ans<<endl;
	}
	else if(a){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans<<endl;
	}
	else if(b){
		cout<<ans<<endl;
	}
	else{
		cout<<0<<endl;
	}
	
	return 0;
}
