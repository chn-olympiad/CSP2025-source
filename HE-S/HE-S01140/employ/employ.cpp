#include<bits/stdc++.h>
#define int long long
using namespace std;
const int it=998244353;
int n,m,o,ans=1,num,cnt;
char s[505];
priority_queue<int> q;
int v[505],k[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>o;
		q.push(o);
	}
	while(!q.empty()){
		cnt=q.top();
		if(q.top()-num==0){
			q.pop();k[cnt]++;
		}
		v[cnt]=q.top();
		q.pop();k[cnt]++;num++;
	}
	for(int i=0;i<505;i++){
		if(k[i]==0) k[i]=1;
		ans=(ans*k[i])%it;
	}
	cout<<ans;
	return 0;
}
