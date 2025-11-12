#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[105];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>=a[1]) k++;
	}
	int nowx=1,nowy=1;
	for(int i=1;i<k;i++){
		if((nowx==n&&nowy%2==1)||(nowx==1&&nowy%2==0)) nowy++;
		else if(nowy%2==1) nowx++;
		else nowx--;
	}
	cout<<nowy<<" "<<nowx;
	return 0;
}
