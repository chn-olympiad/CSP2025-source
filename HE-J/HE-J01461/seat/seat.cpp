#include<bits/stdc++.h>
using namespace std;
int a[110];
int c[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int b=a[1];
	sort(a+1,a+n*m+1);
	bool d=0;
	if(m%2==0){
		d=0;
	}
	else{
		d=1;
	}
	int q=1;
	for(int i=m;i>0;i--){
		if(d==0){
			for(int j=1;j<=n;j++){
				c[j][i]=a[q];
				q++;
			}
			d=1;
		}
		else{
			for(int j=n;j>0;j--){
				c[j][i]=a[q];
				q++;
			}
			d=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]==b){
				cout<<j<<" "<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
