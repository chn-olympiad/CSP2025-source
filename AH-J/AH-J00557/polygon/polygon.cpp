#include<bits/stdc++.h>
using namespace std;
int n,vis[5005],a[5005],ans=0;
void f(int a,int b,int c,int he,int ma){
	if(b==a){
		if(he>ma*2){
			ans++;
			ans%=998244353;
		}return ;
	}if(vis[c]==0){
		vis[c]=1;
		if(a[c]>ma){
			f(a,b+1,c+1,he+a[c],a[c]);
		}else{
			f(a,b+1,c+1,he+a[c],ma);
		}
	}vis[c]=0;
	f(a,b,c+1,he,ma);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		f(i,0,1,0,-1);
	}cout<<ans;
	return 0;
}
