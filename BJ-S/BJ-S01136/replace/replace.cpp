#include <iostream>
#include <algorithm>
using namespace std;

int n,q;
string s1[200005],s2[200005],t1,t2;

/*
namespace B{
	tuple<int,int,int> de[200005];//we need to make b+a*(j-i) to a*(j-i)+b.
	bool check(int id){
		int p1 = -1;
		for(int i = 0;i < s1[id].size(); i++)
			if(s1[id][i] == 'b' && p1 == -1) p1 = i;
			else if(s1[id][i] != 'a') return false;
		int p2 = -1;
		for(int i = 0;i < s2[id].size(); i++)
			if(s2[id][i] == 'b' && p2 == -1) p2 = i;
			else if(s2[id][i] != 'a') return false;
		de[id] = {p1-p2,p1,p2};
		return true;
	}
	void solve(){
		sort(de + 1,de + n + 1);
		while(q--){
			cin >> t1 >> t2;
			int p1 = -1;
			for(int i = 0;i < t1.size(); i++)
				if(t1[i] == 'b' && p1 == -1) p1 = i;
			int p2 = -1;
			for(int i = 0;i < t2.size(); i++)
				if(t2[i] == 'b' && p2 == -1) p2 = i;
			p2 = p1 - p2;
			int p = lower_bound(de + 1,de + n + 1,{p2,p1,-1e9}) - de;
			int s = upper_bound(de + 1,de + n + 1,{p2,1e9,p1+p2}) - de;
			cout << s - p << endl;
		}
	}
}
*/

namespace BF{
	//try to apply each.
	void solve(){
		while(q--){
			cin >> t1 >> t2;
			int cnt = 0;
			for(int i = 1;i <= n; i++)
				for(int j = 0;j + s1[i].size() <= t1.size(); j++){
					bool flag = true;
					for(int k = 0;k < s1[i].size(); k++) if(s1[i][k] != t1[j+k]){
						flag = false;
						break;
					}
					if(!flag) continue;
					for(int k = 0;k < s2[i].size(); k++) if(s2[i][k] != t2[j+k]){
						flag = false;
						break;
					}
					for(int k = j + s1[i].size();k < t1.size(); k++) if(t1[k] != t2[k]){
						flag = false;
						break;
					}
					cnt += flag;
					if(t1[j] != t2[j]) break; //cannot keep it.
				}
			cout << cnt << endl;
		}
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	bool B_flag = true;
	for(int i = 1;i <= n; i++){
		cin >> s1[i] >> s2[i];
		//B_flag &= B::check(i);
	}
	//if(B_flag) B::solve();
	//else
		BF::solve();
	
	
	return 0;
}