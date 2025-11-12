#include<bits/stdc++.h>
using namespace std;

int n,m;
bool e[510];// 0表简单，1表难 
int c[510];
int p[510];
long long ans=0;

void sp(){
	int t=n;
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			t--;
		}
	}
	ans=1;
	for(int i=2;i<=t;i++){
		ans=(ans*i)%998244353;
	}
	return;
}

bool check(){
	int g=0;
	for(int i=1;i<=n;i++){
		if(c[p[i]]<=g || e[i]){
			g++;
//			cout<<"Sorry "<<p[i]<<'\n';
		}
	}
	return (n-g)>=m;
}

void dfs(int x){
	if(x>n){
		if(check()){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(p[i]){
			continue;
		}
		p[i]=x;
//		cout<<x<<"'s rank is "<<i<<'\n';
		dfs(x+1);
		p[i]=0;
	}
	return;
}

int main(){
	freopen("employ1.in","r",stdin);
	freopen("employ.out","w",stdout);

	cin>>n>>m;
	string s;
	cin>>s;
	bool flag=true;
	for(int i=1;i<=n;i++){
		e[i]=(s[i-1]=='0');
		if(e[i]){
			flag=false;
		}
		cin>>c[i];
	}
	if(flag){
		sp();
	}else if(n<=18){
		dfs(1);
	}
	cout<<ans%998244353<<'\n';
	return 0;
}
