#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5;
int n,m,ans;
int a[N],b[N];
bool flag[N];
string s;
void dfs(int x){
	if(x==n+1){
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(a[b[i]]<=cnt){
				cnt++;
				continue;
			}
			if(s[i-1]=='0')
				cnt++; 
			else
				sum++;
		}
		if(sum>=m)
			ans++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!flag[i]){
			b[x]=i;
			flag[i]=true;
			dfs(x+1);
			flag[i]=false;
		}
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
