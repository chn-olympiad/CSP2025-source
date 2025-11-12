#include<bits/stdc++.h>
using namespace std;

int n,m,c[505],cnt,ln;
long long sum,jc[505];
string s;
bool b[505];
void dfs(int x){
	if(cnt>=m){
		sum=(sum+jc[n-x+1])%998244353;
		return;
	}
	if(x>n) return;
	for(int i=1;i<=n;i++)
		if(!b[i]){
			b[i]=1;
			if(c[i]<=ln||s[x-1]=='0'){
				ln++;
				dfs(x+1);
				ln--;
			}
			else{
				cnt++;
				dfs(x+1);
				cnt--;
			}
			b[i]=0;
		}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	jc[0]=1;
	for(long long i=1;i<=n;i++)jc[i]=(jc[i-1]*i)%998244353;
	dfs(1);
	cout<<sum;
	return 0;
} 
