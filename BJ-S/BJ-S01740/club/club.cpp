//holy shit!!!
#include <bits/stdc++.h>
using namespace std;

int n;
int ans = 0;
int one2[100010];//1->other
int c1;
int two2[100010];//2->other
int c2;
int three2[100010];//3->other
int c3;
struct jly{
	int num,club;
}a[100010][5];

bool cmp(jly x,jly y){
	return x.num > y.num;
}

void Main(){
	ans = 0;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i][1].num >> a[i][2].num >> a[i][3].num;
		a[i][1].club = 1,a[i][2].club = 2,a[i][3].club = 3;
		sort(a[i]+1,a[i]+4,cmp);
		if(a[i][1].club == 1){
			one2[++c1] = a[i][1].num-a[i][2].num;
		}
		if(a[i][1].club == 2){
			two2[++c2] = a[i][1].num-a[i][2].num;
		}
		if(a[i][1].club == 3){
			three2[++c3] = a[i][1].num-a[i][2].num;
		}
	}
	sort(one2+1,one2+c1+1);
	sort(two2+1,two2+c2+1);
	sort(three2+1,three2+c3+1);
	int cnt1 = 0,cnt2 = 0,cnt3 = 0;
	for(int i = 1;i <= n;i++){
		ans += a[i][1].num;
		if(a[i][1].club == 1)cnt1++;
		if(a[i][1].club == 2)cnt2++;
		if(a[i][1].club == 3)cnt3++;
	}
	if(cnt1 > n/2){
		for(int i = 1;i <= cnt1-n/2;i++){
			ans -= one2[i];
		}
	}
	if(cnt2 > n/2){
		for(int i = 1;i <= cnt2-n/2;i++){
			ans -= two2[i];
		}
	}
	if(cnt3 > n/2){
		for(int i = 1;i <= cnt3-n/2;i++){
			ans -= three2[i];
		}
	}
	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		Main();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
