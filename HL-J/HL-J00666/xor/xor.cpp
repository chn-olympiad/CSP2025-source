#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int f[N],a[23155][23155];
int n,k,ans,s,xo;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>f[i];
	for(int l=1;l<=n;l++){
		xo=0;
		for(int r=l;r<=n;r++){
			for(int i=l;i<=r;i++){
				if(r-l==0)xo=f[i];
				else if(i==l+1)xo=f[i]^f[i-1];
				else if(i>l+1)xo=xo^f[i];
				if(xo==k)a[r][l]=1;
			}
		}
	}
	int b=1;
	for(int x=1;x<=n;x++){
		for(int y=b;y<=x;y++){
			if(a[x][y]==1){
				ans++;
				b=x+1;
				if(b>n)break;
			}			
		}
	}
	cout<<ans;
	return 0;
}
