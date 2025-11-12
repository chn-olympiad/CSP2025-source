#include<bits/stdc++.h>
using namespace std;
int n,m;
struct f{
	int w;
	int v;
}a[10000];
int r;
int p;
bool cmp(f x,f y){
	return x.v > y.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	r = n * m;
	for(int i = 1;i <= r;i ++){
		cin >> a[i].v;
		a[i].w = i;
	}
	sort(a + 1,a + r + 1,cmp);
	p = 1;
	for(int i = 1;i <= m;i ++){
		if(i % 2 == 1){
			for(int j = 1;j <= n;j ++){
				if(a[p].w == 1){
					cout << i << ' ' << j;
					return 0;
				}
				p ++;
			}
		}
		else{
			for(int j = n;j >= 1;j --){
				if(a[p].w == 1){
					cout << i << ' ' << j;
					return 0;
				}
				p ++;
			}
		}
	}
	return 0;
}
