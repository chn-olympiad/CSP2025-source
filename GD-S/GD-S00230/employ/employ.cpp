#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,m,s[501],c[501];
char t;
bool a[501];
void js(int cs,int jj,int rs){
	if(cs==n+1){
		if(rs>=m){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			a[i]=1;
			if(s[cs]==1&&c[i]>jj){
				js(cs+1,jj,rs+1);
			}else{
				js(cs+1,jj+1,rs);
			}
			a[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t;
		s[i]=t-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	js(1,0,0);
	cout<<ans;
	return 0;
}
