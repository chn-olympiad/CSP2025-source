#include <bits/stdc++.h>
using namespace std;
int num[105];
int seet[15][15];
int n,m,f,p,R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	f = m%2;
	for(int i=0;i<n*m;i++){
		cin>>num[i];
	}
	R = num[0];
	sort(num,num+n*m);
	for(int i=m-1;i>=0;i--){
		if(f==0){
			for(int j=0;j<n;j++){
				seet[j][i] = num[p];
				p++;
			}
			f = 1;
		}
		else{
			for(int j=n-1;j>=0;j--){
				seet[j][i] = num[p];
				p++;
			}
			f = 0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(seet[i][j]==R){
				cout<<j+1<<' '<<i+1;
				return 0;
			}
		}
	}
	return 0;
}
