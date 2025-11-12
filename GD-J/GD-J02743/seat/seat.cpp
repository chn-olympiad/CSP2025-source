#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 20;
int n,m;
string s;
struct str{
	int x,id;
}a[N];
bool cmp(str p,str q){
	return p.x > q.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i].x;
		a[i].id = i;
	}	
	sort(a+1,a+1+n*m,cmp);
	int l = 1,r = 1;
	for(int i = 1;i <= n * m;i++){
		if(a[i].id == 1){
			break;
		}
		if(r % 2 == 1){
			if(l == n) r++;
			else l++;
		}else{
			if(l == 1) r++;
			else l--;
		}
	}
	cout << r << " " << l;
	return 0;
}
