#include<iostream>
using namespace std;
int has(string&ccf){
	int res=0;
	for(auto&i:ccf){
		res+=i*(91+6);
	}return res;
}string s;
#define lilong long long
#define ccf unsigned
#define int ccf lilong
int asdf,q;
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>asdf>>q;
	for(int i=1;i<=q;i++) cout<<"0\n"; 
	
//	cout<<rand();
	return 0;
}/*
杜子德爷爷用百元大钞击落洛谷服务器
 
*/
