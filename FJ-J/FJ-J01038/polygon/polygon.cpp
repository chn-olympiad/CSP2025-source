#include<bits/stdc++.h>
using namespace std;
int a[1005],n;
bool cmp(int a,int b){return a>b;}
int dfs(int x,int c,int ma,int num){
	long long ss=0;
	if(c>=3){
		if(num>ma*2) ss++;
	}
	for(int i=x+1;i<=n;i++) ss=ss%998244353+dfs(i,c+1,max(ma,a[i]),num+a[i])%998244353;	
	return ss;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	long long s=0;
	for(int i=1;i<=n-2;i++) s=s%998244353+dfs(i,1,a[i],a[i])%998244353;
	cout << s;
}
