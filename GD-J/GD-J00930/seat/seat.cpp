#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+10;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	int tindex=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(t==a[i]){
			tindex=i;
			break;
		}
	}
	int lie=tindex/n+1;
	int hang=0;
	tindex=tindex%n;
	if(tindex==0){
		lie-=1;
		tindex=n;
	}
	if(lie%2==1){
		hang=tindex;
	}
	else if(lie%2==0){
		hang=n-tindex+1;
	}
	cout<<lie<<" "<<hang;
	return 0;
}
