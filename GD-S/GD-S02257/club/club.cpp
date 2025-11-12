// T1club 
#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen('club.in','r',stdin);
	freopen('club.out','w',stdout);
	cin >> T;
	while(T--){
		int n,a[100010][3],one = 0,two = 0,three = 0,ans = 0;
		cin >> n;
		int half = n / 2;
		for(int i = 1;i <= n;i ++)
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		for(int i = 1;i <= n;i ++){
			int maxn = -114514,loc;
			for(int j = 1;j <= 3;j ++){
				if(a[i][j] > maxn){
					if(j < half){
						maxn = a[i][j];
						loc = j;
					}
					else
						continue;					
				}
			}
			if(loc == 1)
				one ++;
			if(loc == 2)
				two ++;
			if(loc == 3)
				three ++;
			ans += a[i][loc];
		}
		cout << ans << "\n";
	}
	return 0;
}
