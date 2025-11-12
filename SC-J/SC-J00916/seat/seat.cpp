#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=15;
struct li{
	int x,i;
}line[N*N];
bool operator > (const li a,const li b){
	return a.x>b.x;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1; i<=n*m; i++){
		cin>>line[i].x;line[i].i=i;
	}
	sort(line+1,line+n*m+1,greater<li>());
//	for(int i=1; i<=n*m; i++) cout<<line[i].i;
	for(int i=1; i<=m; i++){
		if(i&1){
			for(int j=1; j<=n; j++){
				if(line[i*n+j-n].i==1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=n; j>=1; j--){
				if(line[i*n-j+1].i==1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}