#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n,t,x,ans,y;
bool temp[N],num[4],d[4];
struct jg{
	int x,xiabiao;
}a[N],b[N],c[N];
bool cmp(int x,int y){
    return x > y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1;i <= n;i++){
			cin >> a[i].x >> b[i].x >> c[i].x;
			d[1] = a[i].x;d[2] = b[i].x;d[3] = c[i].x;
			sort(d + 1,d+ 4,cmp);
			a[i].xiabiao = b[i].xiabiao = c[i].xiabiao = i;
	        x = max(a[i].x,max(b[i].x,c[i].x));
	        //if (x == a[i].x) {num[1]++;one[i] = a[i].x;}
	        //if (x == b[i].x) {num[2]++;two[i] = b[i].x;}
	        //if (x == c[i].x) {num[3]++;three[i] = c[i].x}
	        ans += x;
		}
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
