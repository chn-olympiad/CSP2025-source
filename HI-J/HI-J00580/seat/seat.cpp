#include<bits/stdc++.h>
using namespace std;
int a[15][15],cnt,b[1000000],c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	cnt=0;
	for(int i=0;i<n*m;i++){
		cin >> b[cnt];
		cnt++;
	}
	int x=b[0];
	sort(b,b+cnt);
	c=n*m-1;
	cnt=0;
	for(int i=1;i<=m;i++){
		if((cnt/n)%2==0){
			for(int j=1;j<=m;j++){
				a[i][j]=b[c];
				cnt++;
				c--;
			}
		} else {
			for(int j=m;j>0;j--){
				a[i][j]=b[c];
				cnt++;
				c--;
			}
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=m;i++){
			if(a[i][j]==x) cout << i << ' ' << j;
			
		}
	}
	return 0;
}

