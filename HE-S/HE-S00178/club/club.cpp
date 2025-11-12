#include<bits/stdc++.h>
using namespace std;
int m,n;
struct ss{
	int a1,b1,c1;
	long long y;
}s[1000000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int q;
	cin >> q;
	for(;q > 0;q--){
		long long ans = 0;
		int u = 3;
		cin >> n;
		int a,b,c;
		cin >> a >> b >> c;
		s[1].a1++;
		s[1].y = a;
		ans = max(ans,s[1].y);
		s[2].b1++;
		s[2].y = b;
		ans = max(ans,s[2].y);
		s[3].c1++;
		s[3].y = c;
		ans = max(ans,s[3].y);
		for(int j = 1;j < n;j++){
			int x = 0;
			cin >> a >> b >> c;
			for(int i = 1;i <= u;i++){
				if(s[i].b1 < n / 2 && s[u + x].y + b > ans - 200000){
					x++;
					s[u + x].b1 = s[i].b1 + 1;
					s[u + x].a1 = s[i].a1;
					s[u + x].c1 = s[i].c1;
					s[u + x].y = s[i].y + b;
					ans = max(ans,s[u + x].y);
				}if(s[i].c1 < n / 2 && s[u + x].y + b > ans - 200000){
					x++;
					s[u + x].c1 = s[i].c1 + 1;
					s[u + x].b1 = s[i].b1;
					s[u + x].a1 = s[i].a1;
					s[u + x].y = s[i].y + c;
					ans = max(ans,s[u + x].y);
				}if(s[i].a1 < n / 2){
					s[i].a1 = s[i].a1 + 1;
					s[i].y = s[i].y + a;
					ans = max(ans,s[i].y);
				}
			}
			u += x;
		}
		cout << ans;
		for(int i = 0;i <= u;i++){
			s[i].a1 = 0;
			s[i].b1 = 0;
			s[i].c1 = 0;
			s[i].y = 0;
		}
	}
}
