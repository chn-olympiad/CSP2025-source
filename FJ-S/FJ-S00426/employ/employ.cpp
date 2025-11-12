#include<bits/stdc++.h>
using namespace std;
int n,m,a[510],b[510],c[510],d[510]={0},ans=0;
void sb(int x){
	if(x>n){
		int kill=0,use=0;
		for(int i=1;i<=n;i++){
			if(kill>=b[c[i]]){
				kill++;
			}
			else if(a[i]==0){
				kill++;
			}
			else use++;
		}
		if(use>=m){
			ans++;
			ans=ans%998244353;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(d[i]==1) continue;
			c[x]=i;
			d[i]++;
			sb(x+1);
			d[i]--;
		}
	}
}
int main(){
	//¿¿±©Á¦ 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char s;
		cin>>s;
		a[i]=int(s-'0');
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sb(1);
	cout<<ans;
}
