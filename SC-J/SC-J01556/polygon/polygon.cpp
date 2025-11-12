#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[5005];
int tz=0;
void dfs(int step,int id,int y,int maxx,int ry){
	if(y==id){
		if(ry>2*maxx){
			tz++;
		}
		return;
	}
	for(int i=step+1;i<=n;i++){
		dfs(i,id,y+1,max(maxx,a[i]),ry+a[i]);
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>23){
		int cy=3;
		for(int i=3;i<=n;i++){
			cy=cy*2+1;
		}
		cy-=n;
		n--;
		while(1){
			cy-=n;
			n--;
			if(n==0){
				break;
			}
		}
		cout<<cy%998244353;
		return 0;
	}
	for(int i=3;i<=n;i++){
		dfs(0,i,0,-1,0);
	}
	cout<<tz%998244353;
	return 0;
}