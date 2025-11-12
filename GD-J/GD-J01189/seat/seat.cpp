#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],r,xr,yr;
bool cmp(int x,int y){
	return x>y;
}
void solve(int nx,int ny,int nr,int cnt){
//	cout<<ny<<" "<<nx<<" "<<a[cnt]<<endl;
	if(a[cnt]==nr){
		xr=nx;
		yr=ny;
		return;
	}
	if(nx==n&&ny%2==1)	solve(n,ny+1,nr,cnt+1);
	else if(nx==1&&ny%2==0)	solve(1,ny+1,nr,cnt+1);
	else if(ny%2==1)	solve(nx+1,ny,nr,cnt+1);
	else if(ny%2==0) solve(nx-1,ny,nr,cnt+1);
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)	cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	solve(1,1,r,1);
//	cout<<a[3]<<" ";
	cout<<yr<<" "<<xr;
	return 0;
}

