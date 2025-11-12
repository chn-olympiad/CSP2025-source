#include<bits/stdc++.h>
using namespace std;
int n,m,rc,c[105];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n*m;i++) cin>>c[i];
	rc = c[1];
	sort(c+1,c+n*m+1,cmp);
	if (m % 2 == 0){
		int ij = 1;
		for (int i = 1;i <= m;i+=2){
			for (int j = 1;j <= n;j++){
				if (c[ij] == rc){
					cout<<i<<" "<<j;
					return 0;
				}
				else ij++;
			}
			for (int j = n;j >= 1;j--){
				if (c[ij] == rc){
					cout<<i+1<<" "<<j;
					return 0;
				}
				else ij++;
			}
		}
	}
	else{
		int ij = 1;
		for (int i = 1;i <= m-1;i+=2){
			for (int j = 1;j <= n;j++){
				if (c[ij] == rc){
					cout<<i<<" "<<j;
					return 0;
				}
				else ij++;
			}
			for (int j = n;j >= 1;j--){
				if (c[ij] == rc){
					cout<<i+1<<" "<<j;
					return 0;
				}
				else ij++;
			}
		}
		for (int j = 1;j <= n;j++){
			if (c[ij] == rc){
				cout<<m<<" "<<j;
				return 0;
			}
			else ij++;
		}
	}
}