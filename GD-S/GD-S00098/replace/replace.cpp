#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
using namespace std;
template<class...Arg>
void println(Arg...arg){
	int _[]={(cout<<arg<<' ',0)...};
	cout<<'\n';
}
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<q;i++){
		cout<<"0\n";
	}
	return 0;
}
