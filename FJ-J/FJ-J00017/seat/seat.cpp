#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],rs;

bool cmd(int a,int b) { return a>b; }

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	rs=a[1];
	sort(a+1,a+n*m+1,cmd);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(a[(i-1)*n+j]==rs){
				cout<<i<<" ";
				if(i&1) cout<<j;
				else cout<<n-j+1;
				return 0;
			}
	return 0; 
}
