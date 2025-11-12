#include<bits/stdc++.h>
using namespace std;
const int N=998244353;

int n,m,j,ans;
char cc;
int a[505];
int s[505];
int c[505];
int d[505];
int book[505];

void dfs(int j){
	if(j>n){
		int mm=n;
		for(int i=1;i<=n;i++){
			if(d[i]<s[i] || a[i]) mm--;
			if(mm<m) return;
		}
		for(int i=1;i<=n;i++){
			cout<<d[i]<<" ";
		}
		cout<<"\n";
		ans=(ans+1)%N;
		return;
	}
	for(int i=1;i<=n;i++){
		if(book[i]) continue;
		d[j]=c[i];
		book[i]=1;
		dfs(j+1);
		book[i]=0;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>cc;
		int aa=cc-48;
		a[i]=(aa+1)%2;
		s[i]=s[i-1]+a[i];
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
return 0;
}
