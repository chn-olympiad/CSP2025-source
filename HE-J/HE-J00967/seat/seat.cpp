#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105]={0},mc=0,st[11][11]={0};
	cin >> n >> m;
	map<int,int> mp;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
		mp[a[i]]++;
	}
	for(int i=100;i>=1;i--){
		if(mp[i]!=0) mc++;
		if(i==a[1]){
			break;
		}
	}
	//cout << mc << endl;
	int x=1,y=1;
	for(int i=0;i<mc-1;i++){
		//cout << "bl" << endl;
		if((x==n && y%2==1) || (x==1 && y%2==0)){
			y++;
		}else{
			if(y%2==1){
				x++;
			}else{
				x--;
			}
		}
		//cout << x << " " << y << endl;
	}
	cout << y << " " << x;
	return 0;
}
