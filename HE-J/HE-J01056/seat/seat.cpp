#include<bits/stdc++.h>
using namespace std;
int a[21][21];
int t[110];
int n,m;
bool cmp(int x1,int x2){
	return x1>x2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	for(int i = 1;i<=n*m;i++) cin >>t[i];
	int r = t[1];
	sort(t+1,t+n*m+1,cmp);
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		if(i%2==1){
			for(int j = 1;j<=m;j++){
				cnt++;
				if(t[cnt]==r){
					cout <<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j = m;j>=1;j--){
				cnt++;
				if(t[cnt]==r){
					cout <<i<<" "<<j;
					return 0;
				}
			}
		}
	
	}
	return 0;
}

