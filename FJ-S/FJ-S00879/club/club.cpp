#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T,n,k1;
struct Node{
	int a,b,c;
}k[N];
typedef pair<int,int> PII;
PII a1[N],b1[N],c1[N];
vector <int> x,y,z;
bool check(){
	if(x.size() <= n / 2 && y.size() <= n / 2 && z.size() <= n / 2) return 1;
	else return 0;
}
bool cmp(PII A,PII B){
	return A.second > B.second;
}
int get(){
	int ans = 0;
	for(auto t : x) ans += k[t].a;
	for(auto t : y) ans += k[t].b;
	for(auto t : z) ans += k[t].c;
	return ans; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		x.clear(),y.clear(),z.clear();
		cin >> n;
		int ans = 0,k1 = n / 2;
		for(int i = 1; i <= n; i++){
			cin >> k[i].a >> k[i].b >> k[i].c;
			int maxn = max(max(k[i].a,k[i].b),k[i].c);
			if(k[i].a == maxn) x.push_back(i);
			else if(k[i].b == maxn) y.push_back(i);
			else z.push_back(i); 
		}
		int ans1;
		ans1 = get();
		if(check()){
			cout << ans1 << endl;
			continue;
		}
		int top = 0;
		if(x.size() > k1){
			for(auto t : x){
				a1[++top] = {t,max(k[t].b,k[t].c) - k[t].a};
			}
			sort(a1 + 1,a1 + 1 + top,cmp);
			for(int i = 1; i <= x.size() - k1; i++){
				ans1 += a1[i].second;
			}
		}else if(y.size() > k1){
			for(auto t : y){
				b1[++top] = {t,max(k[t].a,k[t].c) - k[t].b};
			}
			sort(b1 + 1,b1 + 1 + top,cmp);
			for(int i = 1; i <= y.size() - k1; i++){
				ans1 += b1[i].second;
			}
		}else{
			for(auto t : z){
				c1[++top] = {t,max(k[t].a,k[t].b) - k[t].c};
			}
			sort(c1 + 1,c1 + 1 + top,cmp);
			for(int i = 1; i <= z.size() - k1; i++){
				ans1 += c1[i].second;
			}
		}
		cout << ans1 << endl;
	}
	return 0;
} 
