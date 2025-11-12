#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1005];
bool cmp(int x,int y){
	return x>y;
}
int b[15][15];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int z=0;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
		if(i==1) z=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int k=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[i][j]=a[k++];
			}
		}else{
			for(int j=n;j>=1;j--){
				b[i][j]=a[k++];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[j][i]==z){
				cout << j << " " << i;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
