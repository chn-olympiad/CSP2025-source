#include <bits/stdc++.h>
#define lint long long
#define endl '\n'
using namespace std;
const int N = 1e5+5;

struct node{
	int x,y,z;
}a[N];

struct number1{
	int idx;
	bool operator >(const number1 &other) const {
		int x = this->idx,y = other.idx;
		int mi1 = min(a[x].x-a[x].y,a[x].x-a[x].z);
		int mi2 = min(a[y].x-a[y].y,a[y].x-a[y].z);
		return mi1 > mi2;
	}
	bool operator <(const number1 &other) const {
		int x = this->idx,y = other.idx;
		int mi1 = min(a[x].x-a[x].y,a[x].x-a[x].z);
		int mi2 = min(a[y].x-a[y].y,a[y].x-a[y].z);
		return mi1 < mi2;
	}
};
struct number2{
	int idx;
	bool operator >(const number2 &other) const {
		int x = this->idx,y = other.idx;
		int mi1 = min(a[x].y-a[x].x,a[x].y-a[x].z);
		int mi2 = min(a[y].y-a[y].x,a[y].y-a[y].z);
		return mi1 > mi2;
	}
	bool operator <(const number2 &other) const {
		int x = this->idx,y = other.idx;
		int mi1 = min(a[x].y-a[x].x,a[x].y-a[x].z);
		int mi2 = min(a[y].y-a[y].x,a[y].y-a[y].z);
		return mi1 < mi2;
	}
};
struct number3{
	int idx;
	bool operator >(const number3 &other) const {
		int x = this->idx,y = other.idx;
		int mi1 = min(a[x].z-a[x].x,a[x].z-a[x].y);
		int mi2 = min(a[y].z-a[y].x,a[y].z-a[y].y);
		return mi1 > mi2;
	}
	bool operator <(const number3 &other) const {
		int x = this->idx,y = other.idx;
		int mi1 = min(a[x].z-a[x].x,a[x].z-a[x].y);
		int mi2 = min(a[y].z-a[y].x,a[y].z-a[y].y);
		return mi1 < mi2;
	}
};

int n;
priority_queue<number1,vector<number1>,greater<number1> > q1;
priority_queue<number2,vector<number2>,greater<number2> > q2;
priority_queue<number3,vector<number3>,greater<number3> > q3;
queue<int > que,que1;

inline void print(){
	while(!q1.empty()){
		cout << q1.top().idx << " ";
		q1.pop();
	}
	cout << endl;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	cin >> T;
	while(T--){
		
		cin >> n;
		
		int in1,in2,in3;
		for(int i = 1; i <= n; i++){
			cin >> in1 >> in2 >> in3;
			a[i] = (node){in1,in2,in3};
			int ma = max(max(in1,in2),in3);
			if(ma == in1) q1.push((number1){i});
			else que.push(i);
		}
		
		while(q1.size() > n/2){
			que.push(q1.top().idx);
			q1.pop();
		}
		
		lint ans = 0;
		if(q1.size() + 1 > n/2){
			while(!q1.empty()){
				ans += a[q1.top().idx].x;
				q1.pop();
			} 
			while(!que.empty()){
				int idx = que.front();
				ans += max(a[idx].y,a[idx].z);
				que.pop();
			}
		}else{
			while(!que.empty()){
				int idx = que.front();
				int ma = max(max(a[idx].x,a[idx].y),a[idx].z);
				if(ma == a[idx].y) q2.push((number2){idx});
				else que1.push(idx);
				que.pop();
			}
			while(q2.size() > n/2){
				que1.push(q2.top().idx);
				q2.pop();
			}
			if(q2.size() + 1 > n/2){
				while(!q1.empty()){
					ans += a[q1.top().idx].x;
					q1.pop();
				} 
				while(!q2.empty()){
					ans += a[q2.top().idx].y;
					q2.pop();
				} 
				while(!que1.empty()){
					int idx = que1.front();
					ans += max(a[idx].x,a[idx].z);
					que1.pop();
				}
			}else{
				while(!que1.empty()){
					int idx = que1.front();
					q3.push((number3){idx});
					que1.pop();
				}
				while(q3.size() > n/2){
					que.push(q3.top().idx);
					q3.pop();
				}
				if(q3.size()+1 > n/2){
					while(!q1.empty()){
						ans += a[q1.top().idx].x;
						q1.pop();
					} 
					while(!q2.empty()){
						ans += a[q2.top().idx].y;
						q2.pop();
					} 
					while(!q3.empty()){
						ans += a[q3.top().idx].z;
						q3.pop();
					} 
					while(!que.empty()){
						int idx = que.front();
						ans += max(a[idx].x,a[idx].y);
						que.pop();
					}
				}else{
					while(!q1.empty()){
						ans += a[q1.top().idx].x;
						q1.pop();
					} 
					while(!q2.empty()){
						ans += a[q2.top().idx].y;
						q2.pop();
					} 
					while(!q3.empty()){
						ans += a[q3.top().idx].z;
						q3.pop();
					} 
				}
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}
