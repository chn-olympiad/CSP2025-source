#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
bool cmp(int x,int y){
	return x >= y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[105],n,m;
    cin >> n >> m;
    for(int i = 1;i <= n *m ;i ++)cin >> a[i];
    int cnt = a[1];
    sort(a + 1,a + 1 + n*m,cmp);
    for(int i = 1;i <= n*m;i ++){
		if(a[i] == cnt){
			int l = i / n + 1;
		if(i % n == 0) l = i / n;
		int h;
		if(l % 2 == 1){
			h = i % n;
			if(h == 0) h = n;
		}else{
			h = i % n;
			if(h == 0) h = 1;
			else h = n + 1 - h;
		}
			cout << l << ' ' << h << endl;
			return 0;
		}
	}
	return 0;
}
