#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s;
const int N=510;
bool b[N];
int a[N],c[N],dele=998224353;
void dfs(int pos,int num,int x){
	if(pos==n){
		if(num>=m) ans++;
		ans%=dele;
		return;
	}
	if(num+n-pos+1<m) return;
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			int numm=num,xx=x;
			if(c[i]>x&&!a[pos+1]) numm++;
			else xx++;
			dfs(pos+1,numm,xx);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') a[i+1]++;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		b[i]=1;
		int k=0;
		if(a[1]==0&&c[i]) k=1;
		dfs(1,k,1-k);
		b[i]=0;
	}
	cout<<ans;
	return 0;
}
