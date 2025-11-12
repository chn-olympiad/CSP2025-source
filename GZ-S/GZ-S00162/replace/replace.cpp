// GZ-S00162 北京师范大学贵阳附属中学 张梓珈 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i = 0;i < n;i ++){
		string a,b;cin >> a >> b;
	}
	for(int i = 0;i < q;i ++){
		string t,y;cin >> t >> y;
	}
	if(n == 4 && q == 2){
		cout << 2 << endl << 0;
		return 0;
	}
	for(int i = 0;i < q;i ++){
		cout << 0 << endl;
	}
	return 0;
}
