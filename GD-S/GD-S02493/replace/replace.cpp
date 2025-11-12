#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct Pair{
	string a;
	string b;
};

vector<int> find(string fa, string so){
	vector<int> ans;
	if(fa.size()<so.size()){
		return ans;
	}
	for(int offset = 0; offset + so.size()<=fa.size();++offset){
		bool flag =1;
		for(int i = 0;i<so.size();++i){
			if(fa[i+offset] != so[i]){
				flag=0;
				break;
			}
		}
		if(flag ==1){
			ans.push_back(offset);
		}
	}
	return ans;
}

bool replace(Pair tar, Pair s, int idx){
	Pair t = tar;
	for(int i =0;i<s.a.size();++i){
		t.a[idx+i] = s.b[i];
	}
	if(t.a==t.b){
		return 1;
	}
	else return 0;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n, qq;cin>>n>>qq;
		int ans = 0;
		vector<Pair> ps;
		vector<Pair> qu;
		for(int i = 0;i<n;++i){
			Pair p;
			cin>>p.a>>p.b;
			ps.push_back(p);
		}
		for(int i = 0;i<qq;++i){
			Pair p;
			cin>>p.a>>p.b;
			qu.push_back(p);
		}
		
		for(auto q: qu){
			ans = 0; 
			for(auto s: ps){
				auto move = find(q.a, s.a);
				for(auto m:move){
					bool b = replace(q, s, m);
					if(b){
					
						++ans;
					}
				}
			}
			cout << ans << '\n';
		}
		
		fclose(stdin);
	fclose(stdout);
		return 0;
}
