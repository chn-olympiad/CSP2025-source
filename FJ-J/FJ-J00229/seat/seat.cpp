#include <bits/stdc++.h>
using namespace std;
int n,m,cj[105],mp[15][15],anscj;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>cj[i];
	}
	anscj=cj[1];
	sort(cj+1,cj+n*m+1,cmp);
	int cnt=1;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				mp[j][i]=cj[cnt];
				if(mp[j][i]==anscj){
					cout<<j<<' '<<i;
					return 0;
				}
				cnt++;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				mp[j][i]=cj[cnt];
				if(mp[j][i]==anscj){
					cout<<j<<' '<<i;
					return 0;
				}
				cnt++;
			}
		}
	}
	
	return 0;
}
