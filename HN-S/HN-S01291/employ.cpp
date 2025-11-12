#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;

int n,m;
int ans = 0;
const int mod = 998244353;
string dif;
int c[505];
int nowans[505];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>dif;
	for(int i = 1;i<=n;i++){
		cin>>c[i];
		nowans[i] = i;
	}
	do{
		int cnt = 0;
		int fail = 0;
		for(int i = 1;i<=n;i++){
//			cout<<nowans[i]<<' ';
			if(fail>=c[nowans[i]]){
				fail++;
				continue;
			}
			if(dif[i-1]=='0'){
				fail++;
			}else cnt++;
		}
//		cout<<endl;
		ans = ans+(cnt>=m);
		ans%=mod;
//		cout<<ans<<' '<<cnt<<endl;
	}while(next_permutation(nowans+1,nowans+1+n));
	cout<<ans;
	return 0;
}

/*
Why the problem this afternoon is so difficult?
Why the problem this morning is so easy?
What are CCF doing about the problems?
I think i've only get 60+16+0+16=92
So difficult. 
Ad: Follow @GeorgeDeng (Uid: 1021786) at www.luogu.com.cn!
I think I can only get 3= QwQ
But I want 1=!
Someone help me!Please! 
*/

