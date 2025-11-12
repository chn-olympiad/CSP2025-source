#include<iostream>
using namespace std;
const int mod=998244353; 
int n,m,sum,c[505],a[505];
bool b[505];
string s;
void dfs(int k){
	if(k>n){
		int num=0;
		for(int i=1;i<=n;i++)
			if(s[i-1]=='1'&&c[a[i]]>=i-num) num++;
		if(num>=m) sum++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!b[i]){
			b[i]=1,a[k]=i;
			dfs(k+1);
			b[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<sum;
	return 0;
}
