#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+3;
int a[MAXN][5];
//int zu[5]={0,0,0,0,0,0};
//int erzu[5]={0,0,0,0,0,0};

int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,zu,manyidu=0;
	cin >> t;
	for (int s=1;s<=t;s++){
		int n;
		cin >> n;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				cin >> a[i][j];
			}
			if (a[i][1]>=a[i][2]){
				if (a[i][1]>=a[i][3]){
					manyidu+=a[s][1];
//					zu[1]++;
				}else {
					manyidu+=a[s][3];
//					zu[3]++;
				}
			}else if (a[i][2]>=a[i][3]){
				manyidu+=a[s][2];
//				zu[2]++;
			}else {
				manyidu+=a[s][3];
//				zu[3]++;
		}
//		if (zu[1]<n/2 && zu[2]<n/2 && zu[3]<n/2){
//		}
		}
		cout << manyidu << '\d';
	}
	return 0;
}
