#include<bits/stdc++.h>
using namespace std;
const int maxn = 100+10;
typedef long long ll;
ll st[maxn][maxn],a[maxn];

bool cmp(ll x,ll y){
	return x>y;
}
int main(){	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll x,y;
	cin>>x>>y;
	ll tot = x*y;
	for(ll i = 1;i<=tot;++i) cin>>a[i];
	ll ans = a[1];
	sort(a+1,a+tot+1,cmp);
//	for(int i = 1;i<=tot;++i) cout<<a[i];
	ll i = 1,j = 1;
	ll m = 1;
	ll ex = 0,ey = 0;
	while(1){
		st[i][j] = a[m];
		if(st[i][j] == ans){
			ex = i;
			ey = j;
			break;
		}
		if(i == x&&j%2 == 1){
			j++;
		}
		else if(i == 1&&j%2 == 0){
			j++;
		}
		else{
			if(j%2 == 1){
				i++;
			}
			else if(j%2 == 0){
				i--;
			}
		}
		m++;
	}
	cout<<ey<<" "<<ex;
	return 0;
}
/*
10 10
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100

10 10
1 2 3 4 5 6 76 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 7 77 78 79 80 81 82 83 92 85 86 87 88 89 90 91 84 93 94 95 96 97 98 99 100
*/