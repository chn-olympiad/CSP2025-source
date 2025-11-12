#include<bits/stdc++.h>
using namespace std;
struct club_{
	int c[3] = {0, 0, 0};
	int c4, c5;
	bool operator<(club_ other) const {
		if(this -> c4 > other.c4){
			return true;
		}else if(this -> c4 == other.c4){
			return this -> c5 > other.c5;
		}
		return false;
	}
};
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	vector<int> answ;
	scanf("%d", &T);
	while(T --){
		int n, ans = 0;
		unsigned long long clubs[3] = {0, 0, 0};
		scanf("%d", &n);
		vector<club_> club(100010);
		for(int i = 0; i < n; i ++){
			scanf("%d%d%d", &club[i].c[0], &club[i].c[1], &club[i].c[2]);
			club_ now = club[i];
			int fav = 0;
			for(int i = 1; i < 3; i ++){
				if(now.c[fav] < now.c[i]){
					fav = i;
				}
			}
			int second = (fav == 0 ? 1 : 0);
			for(int i = second + 1; i < 3; i ++){
				if(now.c[second] < now.c[i] && fav != i){
					second = i;
				}
			}
			club[i].c4 = now.c[fav] - now.c[second];
			club[i].c5 = now.c[second] - now.c[3 - second - fav];
		}
		sort(club.begin(), club.end());
		for(int f = 0; f < n; f ++){
			club_ now = club[f];
			int fav = 0;
			for(int i = 1; i < 3; i ++){
				if(now.c[fav] < now.c[i]){
					fav = i;
				}
			}
			int second = (fav == 0 ? 1 : 0);
			for(int i = second + 1; i < 3; i ++){
				if(now.c[second] < now.c[i] && fav != i){
					second = i;
				}
			}
			if(clubs[fav] < n / 2){
				clubs[fav] ++;
				ans += now.c[fav];
			}else if (clubs[second] < n / 2){
				clubs[second] ++;
				ans += now.c[second];
			}else{
				int z = 0;
				z = 3 - fav - second;
				clubs[z] ++;
				ans += now.c[z];
			}
		}
		answ.push_back(ans);
	}
	for(int i : answ){
		printf("%d\n", i);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
