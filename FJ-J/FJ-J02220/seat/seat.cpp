#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],s[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++) cin>>a[i];
	int r=a[1],idr;
	sort(a+1,a+1+len,cmp);
	for(int i=1;i<=len;i++)
		if(a[i]==r) idr=i;
	int id=1;
	for(int j=1;j<=m;j++){
		if(j%2==1)
			for(int i=1;i<=n;i++){
				s[i][j]=id;
				id++;
			}
		else
			for(int i=n;i>=1;i--){
				s[i][j]=id;
				id++;
			}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]==idr){
				cout<<j<<" "<<i;
				return 0;
			}
	return 0;
}
