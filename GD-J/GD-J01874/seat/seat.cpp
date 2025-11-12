#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> pts(n * m);
	for(int i = 0;i < n * m;i++) cin>>pts[i];
	int tmp = pts[0],ans = 0;
	sort(pts.begin(),pts.end());
	for(int i = 0;i < n;i++){
		if(i % 2 == 0){
			for(int j = 0;j < m;j++){
				cout<<i + 1<<" "<<j + 1<<" "<<pts[n * m - ans - 1]<<endl;
				if(pts[n * m - ans - 1] == tmp){
					cout<<i + 1<<" "<<j + 1;
					return 0;
				}
				ans++;
			}
		}else{
			for(int j = m - 1;j >= 0;j--){
				cout<<i + 1<<" "<<j + 1<<" "<<pts[n * m - ans - 1]<<endl;
				if(pts[n * m - ans - 1] == tmp){
					cout<<i + 1<<" "<<j + 1;
					return 0;
				}
				ans++;
			}
		}
	}
	return 0;
}
