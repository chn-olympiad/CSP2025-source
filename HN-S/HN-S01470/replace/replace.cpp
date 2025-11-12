#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int N=2*1e5+5;
int n,q;
map<pair<string,string>,int> a;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	while(n--){
		string x,y; cin>>x>>y;
		while(x[0]==y[0]){
			x.erase(0,1),y.erase(0,1);
//			cout<<x<<" "<<y<<endl;
		}
		int l=x.size()-1;
		while(x[l]==y[l]){
			x.erase(l,l+1),y.erase(l,l+1);
			l--;
//			cout<<x<<" "<<y<<endl;
		}
//		cout<<x<<" "<<y<<endl<<endl; 
		a[{x,y}]++;
	}
	while(q--){
		string x,y; cin>>x>>y;
		while(x[0]==y[0]){
			x.erase(0,1),y.erase(0,1);
//			cout<<x<<" "<<y<<endl;
		}
		int l=x.size()-1;
		while(x[l]==y[l]){
			x.erase(l,l+1),y.erase(l,l+1);
			l--;
//			cout<<x<<" "<<y<<endl;
		}
		cout<<a[{x,y}]<<endl;
	}
	return 0;
}
/*
1.只能换一次！
2.把一定需要换的范围确定[l,r]
3.在此之外查找每一个包括它的子串 
4.or输入时就修改子串为两段必定不等 

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
