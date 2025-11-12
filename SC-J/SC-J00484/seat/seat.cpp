# include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5;
bool cmp(int a,int b){return a > b;}
int n,m;
int f,f_xy,c,r;
int a[N];
signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out","w",stdout);
	int k = 1;
	cin >> n >> m;
	if(n == 1 && m == 1){
		cout << "1 1";
		return 0;
	}
	cin >> f;
	for(int i = 1;i < n * m;i++) cin >> a[i];
	sort(a + 1,a + 1 + n * m,cmp);
	for(int i = 1;i < n * m;i++){
		if(a[i - 1] > f && f > a[i]){
			c = i / n;
			if(i % n != 0) c++;
			if(c % 2 == 0){
				r = n - i % n + 1;
			}else{
				if(i % n == 0) r = n;
				else	r = i % n;
			}
			break;
		}
	}
	cout << c << " " << r;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 