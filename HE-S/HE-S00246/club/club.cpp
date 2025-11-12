#include<bits/stdc++.h> 
using namespace std;

const int N = 3e5 + 10;

int t, n, temp, fin;
int ans, maxx;
int a[N][4];
bool st[N];

struct node{
	int index, value, part;
}num[N];

bool cmp1(node x, node y) {
//	if (x.part == temp) return 0;
//	if (x.value == y.value && (x.index != y.index)) return a[x.index][temp] > a[y.index][temp];
	return x.value > y.value;
}

bool cmp2(node x, node y) {
//	if (x.part != temp) return 0;
	return x.value > y.value;
}

int main(){
	
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);
	
	cin >> t;
	while (t --){
		cin >> n;
		int cnt = 0;
		for (int i = 1; i <= n; i ++){
			for (int j = 1; j <= 3; j ++){
				cnt ++;
				cin >> a[i][j];
				num[cnt].index = i;
				num[cnt].part = j;
				num[cnt].value = a[i][j];
			}
		}
		for (int no = 1; no <= 3; no ++){
			maxx = 0;
			temp = no;
			ans = 0;
			for (int j = 1; j <= 3; j ++){
				
				if (j == no) continue;
				
				
				sort(num + 1, num + 1 + n, cmp1);
				
//				for (int i = 1; i <= 4; i ++) cout << num[i].value << ' ';
				ans = 0;
				for (int i = 1; i <= n / 2; i ++){
					
					node c;
					if (num[i].part == no) continue;
					
					if (num[i].value == num[i + 1].value){
						if (a[num[i].index][no] > a[num[i + 1].index][no]){
							c = num[i];
							st[num[i].index] = true;
						}
						else{
							c = num[i + 1];
							st[num[i + 1].index] = true;
							i ++;
						}
					}else{
						c = num[i];
						st[num[i].index] = true;
					}
					
					ans += c.value;
//					cout << "      " << ans << "    ";
					
				}
				
				maxx += ans;
				
			}
			
			
			sort(num + 1, num + 1 + n, cmp2);
			for (int i = 1; i <= n / 2; i ++){
			if (st[num[i].index] == false){
					maxx += num[i].value;
					cout << "nihao" << maxx << "nihao" ;
				}
			}
			
			int i = 1, z = 1;
			while (z <= n / 2){
				if (st[num[i].index] == false){
					maxx += num[i].value;
					z ++;
				}else{
					i ++;
				}
			}
			
			for (int i = 1; i <= n; i ++){
				for (int j = 1; j <= 3; j ++){
					st[i] = 0;
				}
			}
			fin = max(maxx, fin);
		}
		
		cout << fin << endl;
	}
	
	return 0;
}
