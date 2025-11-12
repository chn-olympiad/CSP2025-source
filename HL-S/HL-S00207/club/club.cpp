#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct Node{
	long long a,b,c;
}a[maxn];
bool cmp(Node a,Node b){
	return a.a > b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		bool ok1,ok2,ok3;
		ok1 = ok2 = ok3 = 0;
		int n;
		cin >> n;
		int max_join = n / 2;
		for (int i = 1; i <= n; i++){
			cin >> a[i].a >> a[i].b >> a[i].c;
			if(a[i].a){
				ok1 = 1;
			}
			if(a[i].b){
				ok2 = 1;
			}
			if(a[i].c){
				ok3 = 1;
			}
		}
		if(!ok2 && !ok3){
			long long ans = 0;
			sort(a+1,a+n+1,cmp);
			for (int i = 1; i <= n / 2; i++){
				ans += a[i].a;
			}
			cout << ans << endl;
		}else if(!ok3){
			vector<int> a1,a2;
			long long ans1 = 0,ans2 = 0;
			int _1 = 0,_2 = 0;
			for (int i = 1; i <= n ;i++){
				if(a[i].a == a[i].b){
					if(_1 < _2){
						ans1 += a[i].a;
					}else{
						ans2 += a[i].b;
					}
				}else if(a[i].a > a[i].b){
					a1.push_back(i);
					_1++;
					ans1 += a[i].a;
					if(_1 > max_join){
						int max_num = i;
						int max_1 = a[i].a;
						int max_2 = a[i].b;
						for (int i = 0; i < a1.size(); i++){
							if(a[a1[i]].b > max_2 && ((a[a1[i]].a < max_1) || (a[a1[i]].b - max_2 > a[a1[i]].a - max_1))){
								max_num = a1[i];
								max_1 = a[a1[i]].a;
								max_2 = a[a1[i]].b;
							}
						}
						ans1 -= max_1;
						ans2 += max_2;
					}
				}else{
					a2.push_back(i);
					_2++;
					ans2 += a[i].b;
					if(_2 > max_join){
						int max_num = i;
						int max_1 = a[i].a;
						int max_2 = a[i].b;
						for (int i = 0; i < a2.size(); i++){
							if(a[a2[i]].a > max_1 && ((a[a2[i]].b < max_2) || (a[a2[i]].a - max_1 > a[a2[i]].b - max_2))){
								max_num = a2[i];
								max_1 = a[a2[i]].a;
								max_2 = a[a2[i]].b;
							}
						}
						ans1 += max_1;
						ans2 -= max_2;
					}
				}
			}
			cout << ans1 + ans2 << endl;
		}else{
			long long ans = max(max(a[1].a + max(a[2].b ,a[2].c ),a[1].b + max(a[2].a ,a[2].c )),a[1].c + max(a[2].a ,a[2].b ));
			cout << ans << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}