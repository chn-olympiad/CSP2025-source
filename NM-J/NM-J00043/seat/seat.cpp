#include <bits/stdc++.h>
using namespace std;
int a[15][15],s=1;
int b[105];
int c[105];
int flag=0,topm=-1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> b[s];
			s++;
		}
	}
	int flag1=b[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(b[j]>topm){
				topm=b[j];
				flag=j;
			}
		}
		c[i]=topm;
		topm=-1;
		b[flag]=-1;
	}
	s=1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				a[i][j]=c[s];
				s++;
			}
		}else{
			for(int j=m;j>0;j--){
				a[i][j]=c[s];
				s++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(flag1==a[j][i]){
			cout << j << " " << i;
			}
		}
		
	}
		
	
	return 0;
}
