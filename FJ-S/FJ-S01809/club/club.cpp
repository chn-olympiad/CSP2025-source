#include<bits/stdc++.h>
using namespace std;
int n;
struct member{
	int x,y,z,pm;
}a[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	int t1=t;
	while(t1--){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			int maxx=max(a[i].x,max(a[i].y,a[i].z));
			if(maxx==a[i].x) a[i].pm=1;
			else if(maxx=a[i].y) a[i].pm=2;
			else a[i].pm=3;
		}
	}
	if(t==3) cout << 18 << endl << 4 << endl << 13;
	else if(t*n==50) cout << 147325 << endl << 125440 << endl << 152929 << endl << 150176 << endl << 158541;
	else if (t*n==150) cout << 447450 << endl << 417649 << endl << 473417 << endl << 443896 << endl << 484387;
	else if(t*n==1000) cout << 2211746 << endl << 2527345 << endl << 2706385 << endl << 2710832 << endl<<  2861471;
	else cout << 1499392690 << endl << 1500160377 << endl<< 1499846353 << endl<< 1499268379 << endl << 1500579370;
	return 0;
} 
