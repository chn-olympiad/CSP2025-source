#include <bits/stdc++.h>
using namespace std;

int n,q;
struct c{
	string s1;
	string s2;
};
c b;
vector<c> a;

int main(){
	freopen("replace.in","r",stdin); 
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>b.s1>>b.s2;
		a.push_back(b);
	}
	for (int i=1;i<=q;i++){
		cin>>b.s1>>b.s2;
		vector<char> c,d;
		for (int j=0;j<int(b.s1.length());j++) c.push_back(b.s1[i]);
		for (int j=0;j<int(b.s2.length());j++) d.push_back(b.s2[i]);
		for (int j=1;j<=n;j++){
			
		}
	}
	return 0;
}
