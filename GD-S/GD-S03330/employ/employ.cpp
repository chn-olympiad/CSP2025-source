#include<bits/stdc++.h>
using namespace std;

int n,m;
string s;
int c[501];
int a[501];
int ans;


bool check(){
	x++;
	int sum=0;
	for(int i=1;i<=n;i++){
		if(sum>=a[i]){
			continue;
		}
		x++;
		if(s[i-1]=='0'){
			sum+=q.size();
			x=0;
		}
	}
	if(x==m) return 1;
	return 0; 
}

void dfs(int d){
	if(d==n){
		if(check()){
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			a[i]=c[i];
			dfs(d+1);
			a[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		a[1]=c[i];
		dfs(1);
	}
	cout<<ans;
	
	return 0;
}
/*
那一天的忧郁忧郁起来 
*/
