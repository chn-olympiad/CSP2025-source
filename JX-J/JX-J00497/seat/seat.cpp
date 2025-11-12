#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1010][1010],seatnum,temp[1010],seat,l;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	seatnum = n * m;
	for(int i = 1;i <= seatnum;i ++) cin >> temp[i];
	seat = temp[1];
	sort(temp + 1,temp + seatnum + 1,greater<int>());
	for(int i = 1;i <= n;i ++){
		if(i % 2 == 1){
			for(int j = 1;j <= m;j ++){
				a[i][j] =  temp[++ l];
				if(temp[l] == seat)
					cout << i << " " << j << '\n';
			}
		}
		else{
			for(int j = m;j >= 1;j --){
				a[i][j] =  temp[++ l];
				if(temp[l] == seat)
					cout << i << " " << j << '\n';
			}
		}
	}
	return 0;
}
/*
begin time 18:30
end time 22:00

rp++
* 
* 10 10
51 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100
*/
