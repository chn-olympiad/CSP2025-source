#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],v[10005],b[10005],k=998244353,ans=0;
string s;
bool zax(int x,int y,int z){
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'){
			y++;
		}else{
			if(a[b[i]]>y){
				z++;
			}else{
				y++;
			}
		}
	}
	if(z>=m){
		return 1;
	}else{
		return 0;
	}
}
void zay(int x,int y){
	if(y==n){
		if(zax(1,0,0)==1){
			ans++;
			ans%=k;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			b[y+1]=i;
			zay(i,y+1);
			b[y+1]=0;
			v[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	zay(0,0);
	cout<<ans;
	return 0;
}
