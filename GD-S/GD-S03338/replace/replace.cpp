#include<bits/stdc++.h>
using namespace std;
int n, q, ans=0;
const int N=2e5+5;
struct Node{
	string s, t;
	void cinn()
	{
		cin >> s >> t;
	}
};
Node st[N];
string s1, s2, x, y, z, ss;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for(int i=1; i<=n; i++){
		st[i].cinn();
	}
	while(q--){
		ans=0;
		cin >> s1 >> s2;
		x="";
		y="";
		z="";
		ss="";
		for(int i=0; i<s1.size(); i++){
			for(int j=i; j<s1.size(); j++){
				if(i!=0)x=s1.substr(s1[0], i-0);
				else x="";
				y=s1.substr(s1[i], j-i+1);
				if(j!=s1.size())z=s1.substr(s1[j+1], s1.size()-j-1);
				else z="";
				for(int i=1; i<=n; i++){
					if(y==st[i].s){
						ss=x+st[i].t+z;
						if(ss==s2)ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
}
//暴力也不会写…… 
