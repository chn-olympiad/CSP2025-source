#include <bits/stdc++.h>
using namespace std;

int TAT;

int n;
struct Node {
	int x, y, z;
}a[100002], b[100002], c[100002];
bool cmp(const Node &a,const Node &b){
	return max(a.y, a.z) - a.x < max(b.y, b.z) - b.x;
}
int atop, btop, ctop;

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&TAT);
	
	while(TAT--){
		
		scanf("%d",&n);
		atop = 0, btop = 0, ctop = 0;
		for(int i=1;i<=n;i++) {
			Node s;
			scanf("%d%d%d",&s.x,&s.y,&s.z);
			int num = max(max(s.x, s.y), s.z);
			if(num == s.x){
				a[++atop] = s;
			}
			else if(num == s.y){
				b[++btop] = s;
			}
			else if(num == s.z){
				c[++ctop] = s;
			}
		}
		if(btop > n / 2) {
			swap(a, b), swap(atop, btop);
			for(int i=1;i<=atop;i++) swap(a[i].x, a[i].y);
			for(int i=1;i<=btop;i++) swap(b[i].x, b[i].y);
			for(int i=1;i<=ctop;i++) swap(c[i].x, c[i].y);
		}
		if(ctop > n / 2) {
			swap(a, c), swap(atop, ctop);
			for(int i=1;i<=atop;i++) swap(a[i].x, a[i].z);
			for(int i=1;i<=btop;i++) swap(b[i].x, b[i].z);
			for(int i=1;i<=ctop;i++) swap(c[i].x, c[i].z);
		}
		
		if(atop > n / 2){
			sort(a+1,a+atop+1,cmp);
			//for(int i=1;i<=atop;i++) cout << a[i].x << ' ' << a[i].y << ' ' << a[i].z << endl;
			for(int i=atop;i>n/2;i--){
				if(a[i].y > a[i].z) {
					b[++btop] = a[i];
				}
				else {
					c[++ctop] = a[i];
				}
				atop--;
			}
		}
		
		int Ans = 0;
		for(int i=1;i<=atop;i++) Ans += a[i].x;
		for(int i=1;i<=btop;i++) Ans += b[i].y;
		for(int i=1;i<=ctop;i++) Ans += c[i].z;
		
		printf("%d\n",Ans);
	}
	
	return 0;
}

/*

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
