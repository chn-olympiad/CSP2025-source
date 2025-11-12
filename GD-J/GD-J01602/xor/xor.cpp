#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long num[500100];
void xr(int x,int y){
	long long ct=num[x];
	for(int i=x+1;i<=y;i++)
		ct=ct^num[i];
	if(ct==k){
		ans++;
		if(y<n) xr(y+1,y+1);
		else {
			cout<<ans;
			return ;
		}
	}else if(y<n)
		xr(x,y+1);
	else
		xr(x+1,x+1);
	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>num[i];
	xr(1,1);
	return 0;
} 
