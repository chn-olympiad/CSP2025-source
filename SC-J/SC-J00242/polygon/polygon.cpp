#include<bits/stdc++.h>
using namespace std;
int n;
int a[21];
int b[21];
int cnt;
bool check(){
	int maxa=0,sum=0,cn=0;
	for(int i=1;i<=n;i++){
		if(b[i]==1){
			maxa=max(maxa,a[i]);
			sum+=a[i];
			cn++;
		}
	};
	if(cn<3)return 0;
	return sum>2*maxa;
}
int ch[21],uch;
void dfs(int pos){
	if(check()){
		cnt++;
	}
	if(pos>n)return;
	for(int i=pos+1;i<=n;i++){
		b[i]=1;
		dfs(i);
		b[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0);
	cout<<cnt;
	return 0;
}