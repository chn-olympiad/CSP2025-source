#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp (int a, int b){
	return a > b;
}
int n = 0, m = 0, q = 0;// n是行数，m是列数，q是小R的成绩 
vector<int> ad; // 所有成绩储存 
int f(){
	int l = 0, r = n*m;
	while(l<r){
		int mid = (l+ r)/2;
		if(ad[mid]==q){
			return mid;
		}else if(ad[mid] < q){
			r = mid;
		}else{
			l =mid;
		}
	}
	return -1;
}
signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	cin>>q;
	ad.push_back(q);
	for(int i=2;i<=n*m;++i){
		int tmp = 0;
		cin>>tmp;
		ad.push_back(tmp);
	}
	sort(ad.begin(), ad.end(), cmp);
	int d = f();
	int cu = d / n + 1, qi = d % n + 1;
	if(cu % 2 == 0){ // 行号是奇数
		cout<<cu<<" "<<m - qi + 1; 
	}else{
		cout<<cu<<" "<<qi;
	}
	return 0;
}
