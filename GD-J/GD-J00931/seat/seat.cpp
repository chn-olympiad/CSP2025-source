#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[12][12];
int s[120];
int r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	r=s[1];
	sort(s+1,s+n*m+1,greater<int>());
	int x=1,y=1,cnt=1;
	while(cnt<=n*m){
		//get value
		a[x][y]=s[cnt];
		if(a[x][y]==r){
			break;
		}
		cnt++;
		//solve move
		//cerr<<x<<" "<<y<<"\n";
		if(y&1){
			x++;
		}else{
			x--;
		}
		if((y&1)&&x>n){
			x=n;
			y++;
		}else if(!(y&1)&&x<1){
			x=1;
			y++;
		}
		//cerr<<"now x,y:"<<x<<" "<<y<<"\n";
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cerr<<a[i][j]<<" ";
		}
		cerr<<"\n";
	}*/
	cout<<y<<" "<<x<<"\n";
	return 0;
}
