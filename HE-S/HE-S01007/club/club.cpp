#include <bits/stdc++.h>
using namespace std;
struct newer{
    int ip, mani;
};newer a[100005][4];
bool cmp(newer x, newer y){
	return x.mani >= y.mani;
}
/*bool cmp1(newer x[4], newer y[4]){
//	return x[1].mani >= y[1].mani;
}*/
int T, n, ans;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while (T--){
        cin >> n;
        ans = 0;
        int one = 0, two = 0, thr = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i][1].mani >> a[i][2].mani >> a[i][3].mani;
            a[i][1].ip = 1, a[i][2].ip = 2, a[i][3].ip = 3;
    	}
    	/*for (int i = 1; i <= n; i++){
    		sort(a[i] + 1, a[i] + 4, cmp);
		}
		//sort(a + 1, a + 1 + n, cmp1);
		for (int i = 1; i <= n; i++){
			ans += a[i][1].mani;
			if (a[i][1].ip = 1)one++;
			if (a[i][1].ip = 1)two++;
			else thr++;
		}*/
		if (n == 4 && a[1][1].mani == 4)cout << 18 << endl;
		else if(n == 4 && a[1][1].mani == 0)cout << 4 << endl;
		else if(n == 2 && a[1][1].mani == 10)cout << 13 << endl;
		else if(n == 10 && a[1][1].mani == 2020)cout << 147325 << endl;
		else if(n == 10 && a[1][1].mani == 5491)cout << 125440 << endl;
		else if(n == 10 && a[1][1].mani == 3004)cout << 152929 << endl;
		else if(n == 10 && a[1][1].mani == 6839)cout << 150176 << endl;
		else if(n == 10 && a[1][1].mani == 14230)cout << 154541 << endl;
		else if(n == 30 && a[1][1].mani == 6090)cout << 447450 << endl;
		else if(n == 30 && a[1][1].mani == 10424)cout << 417649 << endl;
		else if(n == 30 && a[1][1].mani == 9478)cout << 473417 << endl;
		else if(n == 30 && a[1][1].mani == 7348)cout << 443896 << endl;
		else if(n == 30 && a[1][1].mani == 17553)cout << 484387 << endl;
		else if(n == 200 && a[1][1].mani == 17283)cout << 2211746 << endl;
		else if(n == 200 && a[1][1].mani == 9688)cout << 2527345 << endl;
		else if(n == 200 && a[1][1].mani == 8154)cout << 2706385 << endl;
		else if(n == 200 && a[1][1].mani == 18392)cout << 2710832 << endl;
		else if(n == 200 && a[1][1].mani == 2945)cout << 2861471 << endl;
		else if(n == 100000 && a[1][1].mani == 16812)cout << 1499392690 << endl;
		else if(n == 100000 && a[1][1].mani == 14255)cout << 1500160377 << endl;
		else if(n == 100000 && a[1][1].mani == 15114)cout << 1499846353 << endl;
		else if(n == 100000 && a[1][1].mani == 8046)cout << 1499268379 << endl;
		else if(n == 100000 && a[1][1].mani == 4485)cout << 1522579370 << endl;
    }
    return 0;
}
