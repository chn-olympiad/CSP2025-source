#include<bits/stdc++.h>
using namespace std;
struct Pepo{
	int a,b,c,d;
}pepo[110000];
int t,n,a1,b1,c1,ans,abc[110000],s;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d" ,&t);
	while(t--){
		scanf("%d" ,&n);
		a1 = 0;
		b1 = 0;
		c1 = 0;
		ans = 0;
		s = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d" ,&pepo[i].a,&pepo[i].b,&pepo[i].c);
			if(pepo[i].a >= pepo[i].b && pepo[i].a >= pepo[i].c){
				a1++;
				pepo[i].d = 1;
				ans += pepo[i].a;
			}else if(pepo[i].a <= pepo[i].b && pepo[i].b >= pepo[i].c){
				b1++;
				pepo[i].d = 2;
				ans += pepo[i].b;
			}else if(pepo[i].c >= pepo[i].b && pepo[i].a <= pepo[i].c){
				c1++;
				pepo[i].d = 3;
				ans += pepo[i].c;
			}
		}
		if(a1 <= n / 2 && b1 <= n / 2 && c1 <= n / 2){
			printf("%d\n" ,ans);
			continue;
		}
		if(a1 > n / 2){
			for(int i = 1;i <= n;i++){
				if(pepo[i].d == 1){
					s++;
					abc[s] = min(pepo[i].a - pepo[i].b,pepo[i].a - pepo[i].c);
				}
			}
			sort(abc + 1,abc + s + 1);
			s = 1;
			while(1){
				if(a1 <= n / 2){
					break;
				}
				ans -= abc[s];
				s++;
				a1--;
			}
		}else if(b1 > n / 2){
			for(int i = 1;i <= n;i++){
				if(pepo[i].d == 2){
					s++;
					abc[s] = min(pepo[i].b - pepo[i].a,pepo[i].b - pepo[i].c);
				}
			}
			sort(abc + 1,abc + s + 1);
			s = 1;
			while(1){
				if(b1 <= n / 2){
					break;
				}
				ans -= abc[s];
				s++;
				b1--;
			}
		}else if(c1 > n / 2){
			for(int i = 1;i <= n;i++){
				if(pepo[i].d == 3){
					s++;
					abc[s] = min(pepo[i].c - pepo[i].a,pepo[i].c - pepo[i].b);
				}
			}
			sort(abc + 1,abc + s + 1);
			s = 1;
			while(1){
				if(c1 <= n / 2){
					break;
				}
				ans -= abc[s];
				s++;
				c1--;
			}
		}
		printf("%d\n" ,ans);
	}
	return 0;
}// Ren5Jie4Di4Ling5%
