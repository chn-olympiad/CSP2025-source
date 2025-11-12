#include<bits/stdc++.h>
using namespace std;
#define int long long
#define accept 0
struct stu{
	int a,b,c;
};
bool cmp1(stu a,stu b){return a.a-max(a.b,a.c) > b.a-max(b.b,b.c); }
bool cmp2(stu a,stu b){return a.b-max(a.a,a.c) > b.b-max(b.a,b.c); }
bool cmp3(stu a,stu b){return a.c-max(a.b,a.a) > b.c-max(b.b,b.a); }
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _;
	cin >> _;
	while(_--){
		vector<stu> a,b,c;
		int n;
		cin >> n;
		int ans = 0;
		for(int i =1;i <= n ;i ++){
			stu x;
			cin >> x.a >> x.b >> x.c;
			if(x.a >= x.b && x.a >= x.c){
				a.push_back(x);
				ans += x.a;
			}else if(x.b >= x.a && x.b >= x.c){
				b.push_back(x);
				ans += x.b;
			}else if(x.c >= x.b && x.a <= x.c){
				c.push_back(x);
				ans += x.c;
			}
		}
		if(a.size() > n/2){
			sort(a.begin(),a.end(),cmp1);
			for(int i = a.size()-1;i >= (n/2);i--){
				stu x = a[i];
				ans -= x.a - max(x.b,x.c);
			}
		}else if(b.size() > n/2){
			sort(b.begin(),b.end(),cmp2);
			for(int i = b.size()-1;i >= (n/2);i--){
				stu x = b[i];
				ans -= x.b - max(x.a,x.c);
			}
		}else if(c.size() > n/2){
			sort(c.begin(),c.end(),cmp3);
			for(int i = c.size()-1;i >= (n/2);i--){
				stu x = c[i];
				ans -= x.c - max(x.b,x.a);
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return accept;
}
