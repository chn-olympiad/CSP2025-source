#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[100010][5];
long long cnt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--){
		cnt=0;
		cin >> n;
		for (int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] > a[i][2]){
				a[i][4]=a[i][1];
			}else{
				a[i][4]=a[i][2];
			}
			if (a[i][4] < a[i][3]){
				a[i][4]=a[i][3];
			}
		}
		for (int i=1;i<=3;i++){
			for (int j=1;j<=2;j++){
				int maxf=-1;
				int maxfi=0;
				for (int k=1;k<=n;k++){
					if (a[k][4] == a[k][i]){
						if (maxf < a[k][i]){
							maxf = a[k][i];
							maxfi = k;
						}
					} 
				}
				cnt+=maxf;
				a[maxfi][i] = -2;
			}
		
		}
		cout << cnt << endl;
	}
	return 0;
}
