#include <bits/stdc++.h>
using namespace std;
int n,m,c[510],f[510];
char s[510];
long long sum=0;
void js(int r,int p,int g){
	if(r==n){
		if(p>=m){
			sum++;
			sum%=998244353;
		}
		return;
	}
	r++;
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			if(g>=c[i]) js(r,p,g+1);
			else if(s[r]=='1') js(r,p+1,g);
			else js(r,p,g+1);
			f[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++){
		f[i]=1;
		if(s[1]=='1') js(1,1,0);
		else js(1,0,1);
		f[i]=0;
	}
	cout<<sum;
	return 0;
}
