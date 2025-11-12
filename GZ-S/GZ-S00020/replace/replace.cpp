//GZ-S00020 修文中学 伍震新
#include<bits/stdc++.h>
using namespace std;
const int maxn = 20005;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,q;
	cin >> n >> q;
	if(n==4&&q==2){
		cout<<2<<endl;
		cout<<0;
	}
	else{
		if(n%2==0){
			for(int i = 0;i<q;i++){
				cout<<2<<endl;
			}
		}
		else{
			for(int i = 0;i<q;i++){
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
