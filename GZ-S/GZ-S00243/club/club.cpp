//GZ-S00243 遵义航天中学 李银涛 
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	freopen("club.in","r",stdin);
	cin >> t;
	fclose(stdin);
	for(int l=0;l<t;l++){
		freopen("club.in","r",stdin);
		int n,h=0;
		cin >> n;
		int m[n][3];
		for(int i=0;i<n;i++){
			m[i][4]=0;
			for(int j=0;j<3;j++){
				cin >> m[i][j];
				m[i][4]=max(m[i][4],m[i][j]);
			}
			h+=m[i][4];
		}
		fclose(stdin);
		freopen("club.out","w",stdout);
		cout << h;
	    fclose(stdout);
	}
}
