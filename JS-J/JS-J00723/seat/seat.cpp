#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >>n>>m;
	vector<int> a;
	for (int i = 0;i < n*m;i++){
		int z;
		cin >>z;
		a.push_back(z);
		}
	int r = a[0];
	int rl = 0;
	int an,am = 0;
	sort(a.begin(),a.end());
	for (int i = 0;i < n*m;i++){
		if (a[i] == r){
			rl = n*m - i;
			break;
			}
		}
	int l = rl / n;
	int h = rl % n;
	am = l + 1;
	if (l % 2 == 0){
		if (h == 0){
			an = 1;
			am = l;
			}
		else {
			an = h;
			}
		}
	else {
		if (h == 0){
			an = n;
			am = l;
			}
		else {
			an = n + 1 - h;
			}
		}
	cout <<am<<" "<<an;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
