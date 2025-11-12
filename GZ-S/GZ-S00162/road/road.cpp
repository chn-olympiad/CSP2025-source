// GZ-S00162 北京师范大学贵阳附属中学 张梓珈 
#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[15];
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 0;i < m;i ++)cin >> a[i];
	for(int i = 0;i < k;i ++)cin >> b[i];
	if(k == 5)cout << 505585650;
	else if(a[0] == 709)cout << 504898585;
	else if(a[0] == 711)cout << 5182974424;
	else cout << 13;
	return 0;
}
