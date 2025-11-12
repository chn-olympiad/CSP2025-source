#include<bits/stdc++.h>
using namespace std;
int t ,n;
int s[20000+10][20000+10];
int ans;
int club_max;

int club_max = n/2;
int bumen_one,bumen_two,bumen_three;
int booll(int one;int two;int three){
	int(one >= two >= three)return bumen_one = one,bumen_two = two,bumen_three = three;
	int(one >= three >= two)
}
int(one >= two;)
int main(){
	freopen("club.im","r",stdin);
	freopen("club.out","w",stdout);
	for(int i = 1; i <= n;i++){
		intmaxx = -1;
		for(int j = 1;j <= 3;j++){
			ss[j] = s[i][j];
			maxx = max(maxx,s[i][j]);
		}
		sort(ss + 1;ss + 1 + 3);
		bumen_one == ss[1];
		bumen_two == ss[2];
		bumen_three == ss[3];
		booll(s[i][1],s[i][2],s[i][3]);
		cout << bumen_one << " " << bumen_two << " " << bumen_three;
		ans += maxx;
	}
	int bn_min = min(bumen_max[1],bumen_max[2],bumen_max[3]);
	for(int i = 1;i <= n;i++){
		ans += max;
	}
	cout << ans << endl;
	return 0;
}
