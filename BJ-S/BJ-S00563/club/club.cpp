#include <bits/stdc++.h>
using namespace std;
int read(){
	int x = 0,f = 1;
	char ch = getchar();
	while (!isdigit(ch)){
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
void write(int x){
	if (x < 0){
		putchar('-');
		write(-x);
		return ;
	}
	if (x < 10){
		putchar(x + '0');
		return ;
	}
	write(x / 10);
	putchar(x % 10 + '0');
}
int T;
int n;
struct node {
	int x,y,z;
	int id;
}a[100050];
bool cmp(node p,node q){
	int x1 = max(p.x,max(p.y,p.z)),x2 = p.x + p.y + p.z - max(p.x,max(p.y,p.z)) - min(p.x,min(p.y,p.z)),x3 = min(p.x,min(p.y,p.z));
	int y1 = max(q.x,max(q.y,q.z)),y2 = q.x + q.y + q.z - max(q.x,max(q.y,q.z)) - min(q.x,min(q.y,q.z)),y3 = min(q.x,min(q.y,q.z));
	//cout << q.x << " " << q.y << " " << q.z << " " << q.x + q.y + q.z - max(q.x,max(q.y,q.z)) - min(q.x,min(q.y,q.z)) << " " << endl;
	//cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
	if (x1 - x2 != y1 - y2) return x1 - x2 > y1 - y2;
	else return x2 - x3 > y2 - y3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    T = read();
    while (T--){
		n = read();
		for (int i = 1;i <= n;i++) a[i].x = read(),a[i].y = read(),a[i].z = read(),a[i].id = i;
		sort(a + 1,a + n + 1,cmp);
		//cout << endl << endl;
		//for (int i = 1;i <= n;i++) cmp(a[i],a[i - 1]);
		//cout << endl;
		int cnt1 = 0,cnt2 = 0,cnt3 = 0;
		int ans = 0;
		int id = 0;
		for (int i = 1;i <= n;i++){
			if (cnt1 >= n / 2 || cnt2 >= n / 2 || cnt3 >= n / 2){
				id = i;
				break;
			}
			ans += max(a[i].x,max(a[i].y,a[i].z));
			if (max(a[i].x,max(a[i].y,a[i].z)) == a[i].x) cnt1++;
			else if (max(a[i].x,max(a[i].y,a[i].z)) == a[i].y) cnt2++;
			else cnt3++;
		}
		if (cnt1 + cnt2 + cnt3 == n){
			cout << ans << endl;
			continue;
		}
		if (cnt1 == n / 2){
			for (int i = 1;i <= n;i++) a[i].x = 0;
		} else if (cnt2 == n / 2){
			for (int i = 1;i <= n;i++) a[i].y = 0;
		} else {
			for (int i = 1;i <= n;i++) a[i].z = 0;
		}
		sort(a + id,a + n + 1,cmp);
		for (int i = id;i <= n;i++) ans += max(a[i].x,max(a[i].y,a[i].z));
		cout << ans << endl;
	}
	return 0;
}


