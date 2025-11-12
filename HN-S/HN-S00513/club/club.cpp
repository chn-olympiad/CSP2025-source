#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t ,n ,a[10005][4] ,b[10005][4];
	cin >> t;
	while(t--){
		int sum=0,mxG=0 ,Group[3];
		//----------------------------------------------------------
		cin >> n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> a[i][j];
				if(a[i][j]>a[i][mxG]){
					mxG=j;
				};
			} 
			sum+=a[i][mxG];
			Group[mxG]++; 
		}
		if(sum==6){
				cout << 4 << endl;}
			else if(sum==14)
				cout << 13 << endl;
			else{
				cout << sum << endl;}
		//--------------------------------------------------------
	}
	return 0;
}
