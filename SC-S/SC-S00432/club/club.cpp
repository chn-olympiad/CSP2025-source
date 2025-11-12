#include <bits/stdc++.h>
using namespace std;
bool locked[3]{false, false, false};
int slots[3];
struct node{
	int s[3];
	int preference, ps;
	int p[3];
	int mp, jp;
	int mids,cps;
	bool solved = false;
	int init(){
		if (s[0] > s[1] and s[0] > s[2]){
			preference = 0;
			if(s[1]>s[2]){
				mids = 1;
			}
			else{
				mids = 2;
			}
		}
		else if ( s[1] > s[0] and s[1] > s[2]){
			preference = 1;
			if(s[0]>s[2]){
				mids = 0;
			}
			else{
				mids = 2;
			}
		}
		else if (s[2] > s[0] and s[2] > s[1]){
			preference = 2;
			if(s[0] > s[1]){
				mids = 0;
			}
			else{
				mids = 1;
			}
		}
		ps = s[preference];
		mp = 0;
		jp = 0;
		for(int i = 0; i < 3; i ++){
			p[i] = s[i] - ps;
			if(p[i] < mp){
				mp = p[i];
				cps= i;
			}
		}
		jp = s[mids] - ps;
		return 0;
	}
	operator < (node b){
		if (solved)
		return true;
		else if(b.solved)
		return false;
		else if(locked[mids] and locked[b.mids])
		return mp < b.mp;
		else if (locked[mids])
		return mp < b.jp;
		else if (locked[b.mids])
		return jp < b.mp;
		else
		return jp < b.jp;
	}
};
int run(){
	locked[0] = false;
	locked[1] = false;
	locked[2] = false;
	int n;
	cin>>n;
	vector<node> o(n);
	for(int i = 0; i< n; i ++){
		int a, b, c;
		cin>>a>>b>>c;
		o[i].s[0] = a;
		o[i].s[1] = b;
		o[i].s[2] = c;
		o[i].init();
	}
	for(int i = 0; i < 3; i++){
		slots[i] = n/2;
	}
	int ans = 0;
	sort(o.begin(),o.end());
	for(int i = 0; i < n; i ++){
		int target;
		if (not locked[o[i].preference]){
			target = o[i].preference;
		}
		else if (not locked[o[i].mids]){
			target = o[i].mids;
			
		}
		else{
			target = o[i].cps;
		}
		ans += o[i].s[target];
		slots[target]--;
		o[i].solved = true;
		if(slots[target] == 0){
			locked[target] = true;
			sort(o.begin(),o.end());
		}
		
	}
	cout<<ans<<'\n';
	
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i =0; i < t; i ++){
		run();
	}
	return 0;
}