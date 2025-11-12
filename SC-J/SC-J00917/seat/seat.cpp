#include <bits/stdc++.h>
using namespace std;
int n,m,h,l;
struct node{int val,id;}a[110];
bool cmp(node i,node j){
	return i.val > j.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n * m; ++i)
		cin >> a[i].val,a[i].id = i;
	sort(a + 1,a + n * m + 1,cmp);
	if(a[1].id == 1)return cout << "1 1",0;
	h = 1,l = 1;
	for(int i = 2; i <= n * m; ++i){
		if(l % 2 != 0)h++;
		else h--;
		if(h > m)h = m,l++;
		if(h < 1)h = 1,l++;
		if(a[i].id == 1)return cout << l << " " << h,0;
	}
	return 0;
}