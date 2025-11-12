#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long num[500005];
long long kee[500005];
long long dfs(int now,long long cnt){
	if(now==n+1)
	return cnt;
	if(cnt<=kee[now])
	return cnt;
	else
	kee[now]=cnt;
	long long u=0;
	long long mx=-1;
	for(long long i=now;i<=n;i++){
		u=num[i]^u;
		if(u==ans){
			mx=max(mx,dfs(i+1,cnt+1));
			break;
		}
	}
	if(num[now]!=ans)
	mx=max(mx,dfs(now+1,cnt));
	return mx;
}
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
	cin>>n>>ans;
	memset(kee,-1,sizeof(kee));
	for(long long i=1;i<=n;i++)
	cin>>num[i];
	cout<<dfs(1,0);
    return 0;
}
