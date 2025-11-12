#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,d,e,f,pd[5],ans;
struct ff{
	int x,y,xi,yi;
}c[1000005];
int cmp(ff a,ff b){
	return a.x - a.y > b.x - b.y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> a;
	for(int i = 1; i <= a; i++){
		cin >> b;
		for(int j = 1; j <= b; j++){
			cin >> d >> e >> f;
			if(d <= e && d <= f){
				if(e <= f){
					c[j].x = f;
					c[j].xi = 3;
					c[j].y = e;
					c[j].yi = 2;
				}
				else{
					c[j].x = e;
					c[j].xi = 2;
					c[j].y = f;
					c[j].yi= 3;
				}
			}
			else if(e <= d && e <= f){
				if(d <= f){
					c[j].x = f;
					c[j].xi = 3;
					c[j].y = d;
					c[j].yi = 1;
				}
				else{
					c[j].x = d;
					c[j].xi = 1;
					c[j].y = f;
					c[j].yi = 3;
				}
			}
			else{
				if(e <= d){
					c[j].x = d;
					c[j].xi = 1;
					c[j].y = e;
					c[j].yi = 2;
				}
				else{
					c[j].x = e;
					c[j].xi = 2;
					c[j].y = d;
					c[j].yi= 1;
				}
			}
		}
		sort(c+1,c+1+b,cmp);
		pd[1] = pd[2] = pd[3] = ans = 0;
		for(int j = 1; j <= b; j++){
			if(pd[c[j].xi] == b / 2){
				ans += c[j].y;
				pd[c[j].yi]++;
			}
			else{
				ans += c[j].x;
				pd[c[j].xi]++;
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
