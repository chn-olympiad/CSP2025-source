//GZ-S00230  遵义市第四中学 李星宸 

#include <bits/stdc++.h>
using namespace std;
long long T;
long long n;
long long a_1, a_2, a_3;
long long cnt1, cnt2, cnt3;
long long ans;
bool _flag;
struct edge{
	long long w;
	long long d;
};

edge s[4];

bool cmp(edge x, edge y){
	return x.w > y.w;
}

struct node{
	long long d1;
	long long w1;
	long long d2;
	long long w2;
	bool operator < (const node & er)const{
		return er.w1 > w1;
	}
};
priority_queue <node> q;

struct temp{
	long long w;
	long long d2;
	long long w2;
	bool operator < (const temp &er)const{
		return  er.w - er.w2 < w - w2;
	}
};

priority_queue <temp> d1;
priority_queue <temp> d2;
priority_queue <temp> d3;

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
		
	cin >> T;
	for(int er_mao = 1; er_mao <= T; er_mao++){
		cnt1 = 0;
		cnt2= 0;
		cnt3 = 0;
		while(!q.empty()){
			q.pop();
		}
		while(!d1.empty()){
			d1.pop();
		}
		while(!d2.empty()){
			d2.pop();
		}
		while(!d3.empty()){
			d3.pop();
		}
		
		cin >> n;
		ans = 0;
		for(int i = 1; i <= n; i++){
			cin >> a_1 >> a_2 >> a_3;
			
			s[1].w = a_1, s[1].d = 1;
			s[2].w = a_2, s[2].d = 2;
			s[3].w = a_3, s[3].d = 3;
			sort(s + 1, s + 4, cmp);
//			cout << i << " " << s[1].w << " " << s[2].w << " " << s[3].w << '\n';
			q.push({ s[1].d, s[1].w, s[2].d, s[2].w});
		}
		node t;
		_flag = true;
		while(!q.empty()){
			t = q.top();
			q.pop();
			if(t.d1 == 1){
				if(cnt1 == n / 2){
					if(d1.top().w + t.w2 < d1.top().w2 + t.w1){
						ans -= d1.top().w;
						ans += d1.top().w2 + t.w1;
						d1.pop();
						d1.push({t.w1, t.d2, t.w2});
					}else{
						ans += t.w2;
					}
				}else{
					if(_flag){
						d1.push({t.w1, t.d2, t.w2});
					}
					cnt1++;
					ans += t.w1;
				}
			}else if(t.d1 == 2){
				if(cnt2 == n / 2){
					if(d2.top().w + t.w2 < d2.top().w2 + t.w1){
						ans -= d2.top().w;
						ans += d2.top().w2 + t.w1;
						d2.pop();
						d2.push({ t.w1, t.d2, t.w2});
					}else{
						ans += t.w2;
					}
				}else{
					if(_flag){
						d2.push({t.w1, t.d2, t.w2});
					}
					cnt2++;
					ans += t.w1;
				}
			}else{
				if(cnt3 == n / 2){
					if(d3.top().w + t.w2 < d3.top().w2 + t.w1){
						ans -= d3.top().w;
						ans += d3.top().w2 + t.w1;
						d3.pop();
						d3.push({t.w1, t.d2, t.w2});
					}else{
						ans += t.w2;
					}
				}else{
					if(_flag){
						d3.push({t.w1, t.d2, t.w2});
					}
					cnt3++;
					ans += t.w1;
				}
			}
			if(cnt1 == n /2 || cnt2 == n / 2 || cnt3 == n / 2){
				_flag = false;
			}
		}
		cout << ans <<'\n';
	}
	return 0;
}
