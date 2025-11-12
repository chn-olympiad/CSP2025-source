#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	int cnt=1;
	for (int i=1;i<=m;i++){
		if (i%2==1){
			for (int j=1;j<=n;j++){
				if (a[cnt]==k){
					cout << i << " "<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				cnt++;
			}
		}else{
			for (int j=n;j>=1;j--){
				if (a[cnt]==k){
					cout << i << " "<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				cnt++;
			}
		} 
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
