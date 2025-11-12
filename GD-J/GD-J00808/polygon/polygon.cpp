#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e3+10;
const int maxm=3e7+10;
int a[maxn];

int n,r;
int ret=0;
void dfs(int cur,bool pick,int maxi,int tot){
	if(cur==n+1&&cur>=3){
		ret++;
		return ;
	}
	int newmax=max(maxi,a[cur+1]);
	int newtot=tot+a[cur+1];
	if(newtot>2*newmax&&cur>=3||cur<3){
		dfs(cur+1,1,newmax,newtot);
	}
	dfs(cur+1,0,maxi,tot);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=1;
	}
	if(flag==0){
		cout<<n-2;
	}
	else {
		dfs(0,1,0,0);
		cout<<ret;
	}
	
	
	return 0;
}
