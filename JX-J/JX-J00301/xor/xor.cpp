#include <bits/stdc++.h>
using namespace std;
int n,k,asd[500005],cnt;
bool cbr[500005];
long long yh(int a,int b){
	string a1,b1;
	int a2=0,b2=0;
	while(a){
		if(a%2==1) a1[a2]=1;
		else a1[a2]=0;
		a/=2;
		a2++;
	}
	while(b){
		if(b%2==1) b1[b2]=1;
		else b1[b2]=0;
		b/=2;
		b2++;
	}
	long long qwq=0;
	if(a2>b2) for(int i=b2;i<a2;i++) b1[i]=0;
	if(a2<b2) for(int i=a2;i<b2;i++) a1[i]=0;
	for(int i=max(a2,b2);i>0;i--){
		if(a1[i]!=b1[i]) qwq++;
	}
	return qwq;
}
void dfs(int x,int y){
	if(asd[x]==k){
		cbr[x]=1;
		cnt++;
		dfs(x+1,x+2);
	}
	if(x>=n){
		cout<<cnt;
		exit(0);
	}
	for(int i=x;i<=y;i++){
		if(cbr[i]){
			if(y==n) dfs(x+1,x+2);
			else dfs(x,y+1);
		}
	}
	int aa=0;
	for(int i=x;i<y;i++){
		aa+=yh(asd[i],asd[i+1]);
	}
	if(aa==k){
		 cnt++;
		 for(int i=x;i<=y;i++){
			 cbr[i]=1;
		 }
		 dfs(y+1,y+2);
	}
	if(y==n) dfs(x+1,x+2);
	else dfs(x,y+1);
}
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>asd[i];
	}
	dfs(1,2);
}
