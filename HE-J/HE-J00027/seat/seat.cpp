#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int a[10010];
bool cmp(int x,int y){
	return (x>y);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int z=n*m;
	for(int i=1;i<=z;i++) cin>>a[i];
	int xr=a[1];
	sort(a+1,a+1+z,cmp);
	int l;
	for(int i=1;i<=m*n;i++){
		if(a[i]==xr){
			l=i;
			break;
		}
	}
	int c,r;
	if(l%n==0) c=l/n;
	else c=l/n+1;
	if(c%2==1) r=(l+n-1)%n+1;//jishu
	else r=n-((l+n-1)%n);//oushu
	cout<<c<<" "<<r;
	return 0;
}
