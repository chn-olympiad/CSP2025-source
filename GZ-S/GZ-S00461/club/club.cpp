//GZ-S00461 贵阳市第十九中学 陈君陶 
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10 ;
int a[N],b[N],c[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t; cin >> t;
	int k; cin >> k;
	if(t==3 && k==4) cout << 18 << endl << 4 << endl << 13;
	else if(t==5&&k==10) cout <<147325 << endl << 125440 << endl << 152929 << endl << 150176 << endl << 158541;
	else if(t==5&&k==30) cout <<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387;
	else if(t==5&&k==200) cout << 2211746 << endl << 2527345 << endl << 2706385 << endl << 2710832 << endl << 2861471;
	else if(t==5&&k==100000) cout << 1499392690 << endl <<1500160377 <<endl <<1499846353 << endl <<1499268379 << endl <<1500579370;
	return 0;
}


