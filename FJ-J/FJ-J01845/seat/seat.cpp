#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,a[1000],s[100][100],r,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	k=n*m;
	sort(a+1,a+1+n*m);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				s[j][i]=a[k];
				k--;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				s[j][i]=a[k];
				k--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==r){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
