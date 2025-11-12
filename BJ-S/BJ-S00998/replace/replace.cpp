#include "bits/stdc++.h"
using namespace std;

map<string,string> m;
vector<string> v;
set<int> is;

int main() {
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	string a,b;
	cin>>n>>q;
	for(int i = 1;i <= n;i++) {
		cin>>a>>b;
		m[a] = b;
		v.push_back(a);
	}
	
	while(q--) {
		
		cin>>a>>b;
		
		for(int x = -1;x < v.size();x++) {
			int i = 0;
			if(x != -1) {
				i++;
			}
			for(int y = -1;x < v.size();y++) {
				if(y != -1) {
					i++;
				}
				for(int z = -1;z < v.size();z++) {
					if(z != -1) {
						i++;
					}
					
					vector<int> vx,vy,vz;
					int fx,fy,fz;
					
						if(x != -1) {
							
							while(a.find(v[x]) != string::npos) {
								fx = a.find(v[x]);
								
								string copystr = "";
								for(int i = 0;i < fx;i++) {
									copystr += a[i];
								}
								copystr += m[v[x]];
								for(int i = fx + m[v[x]].size();i < a.size() +  m[v[x]].size();i++) {
									copystr += a[i];
								}
								a = copystr;
							}
						}
						if(y != -1) {
							string copystr = "";
							while(a.find(v[y]) != string::npos) {
								fy = a.find(v[y]);
								
								string copystr = "";
								for(int i = 0;i < fy;i++) {
									copystr += a[i];
								}
								copystr += m[v[y]];
								for(int i = fy + m[v[y]].size();i < a.size() +  m[v[y]].size();i++) {
									copystr += a[i];
								}
								a = copystr;
							}
						}
						if(z != -1) {
							string copystr = a;
							while(a.find(v[z]) != string::npos) {
								fz = a.find(v[z]);
								
								string copystr = "";
								for(int i = 0;i < fz;i++) {
									copystr += a[i];
								}
								copystr += m[v[z]];
								for(int i = fz + m[v[z]].size();i < a.size() +  m[v[z]].size();i++) {
									copystr += a[i];
								}
								a = copystr;
							}
						}
						
					
					
					if(a == b && !is.count(i)) {
						is.insert(i);
						
					}
					
					
					
				}
			}
		}
		
		
	}
	
	
	cout<<is.size();
	
	
	return 0;
}
