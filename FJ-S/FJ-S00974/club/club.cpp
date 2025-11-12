#include <bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
	int i1,i2,i3;
	int h1,h2,h3;
};
bool ljc(node x,node y){
	return x.a > y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for (int i = 1;i <= t;i ++){
		int n;
		cin >> n;
		node m[n + 5];
		int s1 = 0,s2 = 0,s3 = 0,ans = 0;
		int l1 = 9999990,l2 = 9999990,l3 = 9999990,id1,id2,id3;
		for (int j = 1;j <= n;j ++){
			cin >> m[j].a >> m[j].b >> m[j].c;
		}
		if (n <= 200 && m[1].b == 0 && m[1].c == 0){
			sort (m + 1,m + 1 + n,ljc);
			for (int j = 1;j <= n / 2;j ++){
				ans += m[j].a;
			}
		}
		else{
			for (int j = 1;j <= n;j ++){
				if (m[j].a >= m[j].b && m[j].b >= m[j].c){
					m[j].i1 = 1;
					m[j].i2 = 2;
					m[j].i3 = 3;
					m[j].h1 = m[j].a - m[j].b;
					m[j].h2 = m[j].a - m[j].c;
					m[j].h3 = m[j].b - m[j].c;
			}
				else if (m[j].a >= m[j].c && m[j].c >= m[j].b){
					m[j].i1 = 1;
					m[j].i2 = 3;
					m[j].i3 = 2;
					m[j].h1 = m[j].a - m[j].c;
					m[j].h2 = m[j].a - m[j].b;
					m[j].h3 = m[j].c - m[j].b;
				}
				else if (m[j].b >= m[j].a && m[j].a >= m[j].c){
					m[j].i1 = 2;
					m[j].i2 = 1;
					m[j].i3 = 3;
					m[j].h1 = m[j].b - m[j].a;
					m[j].h2 = m[j].b - m[j].c;
					m[j].h3 = m[j].a - m[j].c;
				}
				else if (m[j].c >= m[j].a && m[j].a >= m[j].b){
					m[j].i1 = 2;
					m[j].i2 = 3;
					m[j].i3 = 1;
					m[j].h1 = m[j].c - m[j].a;
					m[j].h2 = m[j].c - m[j].b;
					m[j].h3 = m[j].a - m[j].b;
				}
				else if (m[j].b >= m[j].c && m[j].c >= m[j].a){
					m[j].i1 = 3;
					m[j].i2 = 1;
					m[j].i3 = 2;
					m[j].h1 = m[j].b - m[j].c;
					m[j].h2 = m[j].b - m[j].a;
					m[j].h3 = m[j].c - m[j].a;
				}
				else if (m[j].c >= m[j].b && m[j].b >= m[j].a){
					m[j].i1 = 3;
					m[j].i2 = 2;
					m[j].i3 = 1;
					m[j].h1 = m[j].c - m[j].b;
					m[j].h2 = m[j].c - m[j].a;
					m[j].h3 = m[j].b - m[j].a;
				}
			}
			for (int j = 1;j <= n;j ++){
				if (m[j].i1 == 1){
					if (s1 < (n / 2)){
						s1 ++;
						ans += m[j].a;
						if (m[j].h1 < l1 || (m[j].h1 == l1 && m[j].h2 < m[id1].h2)){
							l1 = m[j].h1;
							id1 = j;
						}
					}
					else {
						if (m[j].h1 > l1 || (m[j].h1 == l1 && m[j].h2 > m[id1].h2)){
							ans = ans + m[j].a - m[id1].a;
							if (m[id1].i2 == 2){
								ans += m[id1].b;
								s2 ++;
								if (m[id1].h3 < l2){
									l2 = m[id1].h3;
									id2 = id1;
								}
							}
							if (m[id1].i3 == 2){
								ans += m[id1].c;
								s3 ++;
								if (m[id1].h3 < l3){
									l3 = m[id1].h3;
									id3 = id1;
								}
							}
						}
						else {
							if (m[j].i2 == 2){
								s2 ++;
								ans += m[j].b;
								if (m[j].h3 < l2 && m[j].h2 < m[id2].h2){
									l2 = m[j].h3;
									id2 = j;
								}
							}
							if (m[j].i3 == 2){
								s3 ++;
								ans += m[j].c;
								if (m[j].h3 < l3 && m[j].h2 < m[id3].h2){
									l3 = m[j].h3;
									id3 = j;
								}
							}
						}
					}
				}
				if (m[j].i2 == 1){
					if (s2 < (n / 2)){
						s2 ++;
						ans += m[j].b;
						if (m[j].h1 < l2 || (m[j].h1 == l2 && m[j].h2 < m[id2].h2)){
							l2 = m[j].h1;
							id2 = j;
						}
					}
					else {
						if (m[j].h1 > l2 || (m[j].h2 == l2 && m[j].h2 > m[id2].h2)){
							ans = ans + m[j].b - m[id2].b;
							if (m[id2].i1 == 2){
								s1 ++;
								ans += m[id2].a;
								if (m[id2].h3 < l1){
									l1 = m[id2].h3;
									id1 = id2;
								}
							}
							if (m[id2].i3 == 2){
								s3 ++;
								ans += m[id2].c;
								if (m[id2].h3 < l3){
									l3 = m[id2].h3;
									id3 = id2;
								}
							}
						}
						else {
							if (m[j].i1 == 2){
								s1 ++;
								ans += m[j].a;
								if (m[j].h3 < l1  || (m[j].h1 == l1 && m[j].h2 < m[id1].h2)){
									l1 = m[j].h3;
									id1 = j;
								}
							}
							if (m[j].i3 == 2){
								s3 ++;
								ans += m[j].c;
								if (m[j].h3 < l3  || (m[j].h1 == l1 && m[j].h2 < m[id3].h2)){
									l3 = m[j].h3;
									id3 = j;
								}
							}
						}
					}
				}
				if (m[j].i3 == 1){
					if (s3 < (n / 2)){
						s3 ++;
						ans += m[j].c;
						if (m[j].h1 < l3 || (m[j].h1 == l3 && m[j].h2 < m[id3].h2)){
							l3 = m[j].h1;
							id3 = j;
						}
					}
					else {
						if (m[j].h1 > l3 || (m[j].h2 == l3 && m[j].h2 > m[id3].h2)){
							ans = ans + m[j].c - m[id3].c;
							if (m[id3].i1 == 2){
								s1 ++;
								ans += m[id3].a; 
								if (m[id3].h3 < l1){
									l1 = m[id3].h3;
									id1 = id3;
								}
							}
							if (m[id3].i2 == 2){
								s2 ++;
								ans += m[id3].b; 
								if (m[id3].h3 < l2){
									l2 = m[id3].h3;
									id2 = id3;
								}
							}
						}
						else {
							if (m[j].i2 == 2){
								s2 ++;
								ans += m[j].b;
								if (m[j].h3 < l2  || (m[j].h1 == l1 && m[j].h2 < m[id2].h2)){
									l2 = m[j].h3;
									id2 = j;
								}
							}
							if (m[j].i1 == 2){
								s1 ++;
								ans += m[j].a;
								if (m[j].h3 < l1  || (m[j].h1 == l1 && m[j].h2 < m[id1].h2)){
									l1 = m[j].h3;
									id1 = j;
								}
							}
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
