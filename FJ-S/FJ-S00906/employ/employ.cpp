#include<bits/stdc++.h>
using namespace std;
long long m,n,c[505],p[505],cnt=0,sum,fq;
string s;
void v(int z){
	for(int j=z;j<=n;j++){
		c[j]-=1;
	}
	return;
}
void dfs(int k){
	if(k==n){
		sum=0;
		fq=0;
		for(int i=1;i<=n;i++){
			if(p[i]&&c[i]>=0){
				sum+=1;
			}else{
				if(c[i]>=0){
					fq+=1;
					v(i);
				}
			}
		}
		if(sum>=m){
			cnt+=1;
		}
		return;
	}
	for(int i=k;i<=n;i++){
		swap(c[k],c[i]);
		dfs(k+1);
		swap(c[k],c[i]);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) p[i]=int(s[i])-'0';
	dfs(1);
	cnt%=998244353;
	cout<<cnt;
	return 0;
}
