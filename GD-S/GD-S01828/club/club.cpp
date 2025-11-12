#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t --){
		long long ans = 0;
		int n;
		cin >> n;
		vector<int> vec[5];
		int _1 = 0,_2 = 0,_3 = 0;
		int a,b,c;
		for(int i = 1;i <= n;i ++){
			scanf("%d%d%d",&a,&b,&c);
			int ma = max(a,max(b,c));
			ans += ma;
			if(ma == a)_1 ++,vec[1].push_back(ma - max(b,c));
			else if(ma == b)_2 ++,vec[2].push_back(ma - max(a,c));
			else if(ma == c)_3 ++,vec[3].push_back(ma - max(b,a));
		} 
		for(int i = 1;i <= 3;i ++)
			sort(vec[i].begin(),vec[i].end());
		if(_1 > n / 2)for(int i = 0;i < _1 - n / 2;i ++)ans -= vec[1][i];
		else if(_2 > n / 2)for(int i = 0;i < _2 - n / 2;i ++)ans -= vec[2][i];
		else if(_3 > n / 2)for(int i = 0;i < _3 - n / 2;i ++)ans -= vec[3][i];
		cout << ans << endl;
	}
	return 0;
} 
