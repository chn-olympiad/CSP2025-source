#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
typedef long long ll;

struct node{
	int g1,g2,g3,id;
}a[N];
priority_queue<int,vector<int>,greater<int> >q1,q2,q3; 
void cl(int n){
	for(int i = 1;i <= n;i++){
		a[i].g1 = a[i].g2 = a[i].g3 = a[i].id = 0;
	}
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	while(!q3.empty()) q3.pop();
}



int my_abs(int g){
	if(g > 0) return g;
	return -g;
}

//priority_queue<node>q1,q2,q3; 

void solve(){
	int n;
	cin >> n;
	cl(n);
	ll ans = 0;
	for(int i = 1;i <= n;i++){
		a[i].id = i;
		cin >> a[i].g1 >> a[i].g2 >> a[i].g3;
		int k = max({a[i].g1 , a[i].g2 , a[i].g3});
		int m = 0;
		if(k == a[i].g1){
			m = min(my_abs(k - a[i].g2),my_abs(k - a[i].g3));
		}
		
		else if(k == a[i].g2){
			m = min(my_abs(k - a[i].g1),my_abs(k - a[i].g3));
		}
		
		else{
			m = min(my_abs(k - a[i].g1),my_abs(k - a[i].g2));
		}
		
		
		int a1 = a[i].g1,a2 = a[i].g2,a3 = a[i].g3;
		if(a1 >= a2 && a1 >= a3){
			if(q1.size() < n/2){
				ans += a1;
				q1.push(m);
				continue;
			}
			else{
				int u1 = q1.top();
				if(u1 > m){
					ans += a1 - m;
					continue;
				}else{
					ans -= u1;
					q1.pop();//删除u1 
					q1.push(m);
					ans += a1;//加上a[i]的值 
				}
				continue;
			}
		}
		else if(a2 >= a1 && a2 >= a3){
			
			if(q2.size() < n/2){
				ans += a2;
				q2.push(m);
				continue;
			}
			else{
				int u2 = q2.top();//转移到其他地方的代价 
				if(u2 > m){
					ans += a2 - m;
				}else{
					ans -= u2;
					q2.pop();//删除u2 
					q2.push(m);
					ans += a2;//加上a[i]的值 
				}
				continue;
			}
		}else{
			if(q3.size() < n/2){
				ans += a3;
				q3.push(m);
				continue;
			}
			else{
				int u3 = q2.top();
				if(u3 > m){
					ans += a3 - m;
				}else{
					ans -= u3;
					q3.pop();//删除u3 
					q3.push(m);
					ans += a1;//加上a[i]的值 
				}
				continue;
			}			
		}
	}
	cout << ans << '\n'; 
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

