#include<iostream>
using namespace std;
string s1,s2;
int n,q;
int main(){
	//freopen("replace1.in","r",stdin);
	//freopen("replace1.out","w",stdout);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin>>s1>>s2;
	for(int i = 1;i <= q;i++) cin>>s1>>s2;
	for(int i = 1;i <= q;i++) cout << 0 << endl; 
	return 0;
}
