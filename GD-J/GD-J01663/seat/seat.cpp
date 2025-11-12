#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s[105],a[105][105],k,cnt,cnt1,x,y;
bool flag=true;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int step,int wei,int l,int r){
	x=l,y=r;
	if(step==1){
		return;
	}
	if(wei==-1){
		if(l==n){
			wei=0;
			flag=false;
			dfs(step-1,wei,l,r+1);
		}
		else{
			dfs(step-1,wei,l+1,r);	
		}
	}
	else if(wei==1){
		if(l==1){
			wei=0;
			flag=true;
			dfs(step-1,wei,l,r+1);
		}
		else{
			dfs(step-1,wei,l-1,r);
		}
	}
	else{
		if(flag==false){
			wei=1;
			dfs(step-1,wei,l-1,r);
		}
		else{
			dfs(step-1,wei,l+1,r);
		}
	}
	return;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	cnt=s[1];
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(s[i]==cnt){
			cnt1=i;
			break;
		}
	}
	dfs(cnt1,-1,1,1);
	cout<<y<<" "<<x;
	return 0;
}
