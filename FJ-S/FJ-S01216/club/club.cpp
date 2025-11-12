#include<bits/stdc++.h>
using namespace std;

int t,n,fj,jx;
long long a[100005][5],mn;
int main(){
//	freopen("club1.in","r",stdin);
//	freopen("club1.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int m=1;m<=t;m++){
		cin >> n;
		int nm=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				mn=max(mn,a[i][j]);
				jx=j;
			}
		}
		cout << fj << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
