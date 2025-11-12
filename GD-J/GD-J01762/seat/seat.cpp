#include<bits/stdc++.h>
using namespace std;
int ans[16][16];
int gr[256];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int xm = 0;
	for(int i = 1;i<=n*m;i++){
		cin>>gr[i];
	}
	xm = gr[1];
	sort(gr+1,gr+1+(m*n),cmp);
	int cnt = 1;
	int c = 1;
	for(int j = 1;j<=m;j++){
		if(cnt%2 == 1){
			for(int i = 1;i<=n;i++){
				if(gr[c] == xm){
					cout<<j<<' '<<i;
					return 0;
				}
				c++;
			}
		}
		else{
			for(int i = n;i>0;i--){
				if(gr[c] == xm){
					cout<<j<<' '<<i;
					return 0;
				}
				c++;
			}
		}
		cnt++;
	}
	return 0;
}
