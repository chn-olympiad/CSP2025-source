# include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int t,n,ans = 0;
bool tpA,tpB;
vector<int> prin;

struct per {
	int a1,a2,a3;
	int a1a2,a2a3,a1a3;
	int a123;
};
per a[N];

bool cmpTPA (per x,per y) {
	return x.a1 > y.a1;
}
bool cmpTPB (per x,per y) {
	return x.a1a2 > y.a1a2;
}

bool cmp (per x,per y) {
	return x.a123 > y.a123;
}

int pre1[N],pre2[N],pre3[N];
int idx1=0,idx2=0,idx3=0;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t --) {
		cin >> n;
		tpA = true,tpB = true;
		ans = 0;
		for (int i = 1;i <= n;i ++) {
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if (a[i].a2 != 0 || a[i].a3 != 0) tpA = false;
			if (a[i].a3 != 0) tpB = false;
			a[i].a1a2 = a[i].a1 - a[i].a2;
			a[i].a1a3 = a[i].a1 - a[i].a3;
			a[i].a2a3 = a[i].a2 - a[i].a3;
			if (a[i].a1 == max({a[i].a1,a[i].a2,a[i].a3})) {
				idx1++;pre1[idx1] = i;
			}
			else if (a[i].a2 == max({a[i].a1,a[i].a2,a[i].a3})) {
				idx2++;pre2[idx2] = i;
			}
			else if (a[i].a3 == max({a[i].a1,a[i].a2,a[i].a3})) {
				idx3++;pre3[idx3] = i;
			}
		}
		if (tpA) {
			sort(a+1,a+1+n,cmpTPA);
			int nc2 = n / 2;
			for (int i = 1;i <= nc2;i ++) ans += a[i].a1;
			prin.push_back(ans);
			continue;
		}
		if (tpB) {
			sort(a+1,a+1+n,cmpTPB);
			int nc2 = n / 2;
			for (int i = 1;i <= nc2;i ++) ans += a[i].a1;
			for (int i = nc2+1;i <= n;i ++) ans += a[i].a2;
			prin.push_back(ans);
			continue;
		}
		if (max({idx1,idx2,idx3}) <= n/2) {
			//cout << ans << endl;
			for (int i = 1;i <= idx1;i ++) {
				ans += a[pre1[i]].a1;
				//cout << i << "   " << ans << endl;
			}
			//cout << idx1 << endl;
			for (int i = 1;i <= idx2;i ++) ans += a[pre2[i]].a2;
			//cout << ans << endl;
			for (int i = 1;i <= idx3;i ++) ans += a[pre3[i]].a3;
			//cout << ans << endl;
			prin.push_back(ans);
			continue;
		}
		if (max({idx1,idx2,idx3}) == idx2) {
			for (int i = 1;i <= n;i ++) swap(a[i].a1,a[i].a2);
		}
		else if (max({idx1,idx2,idx3}) == idx3) {
			for (int i = 1;i <= n;i ++) swap(a[i].a1,a[i].a3);
		}
		for (int i = 1;i <= n;i ++) {
			a[i].a123 = min(a[i].a1-a[i].a2,a[i].a1-a[i].a3);
		}
		sort(a+1,a+1+n,cmp);
		int nc2 = n / 2;
		for (int i = 1;i <= n;i ++) ans += a[i].a1;
		//cout << ans << endl;
		for (int i = nc2+1;i <= n;i ++) ans -= a[i].a123;
		prin.push_back(ans);
		//cout << ans << endl;
	}
	for (int i : prin) cout << i << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
