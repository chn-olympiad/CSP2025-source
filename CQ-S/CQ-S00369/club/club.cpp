#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
struct node{
	int x,y,z,id;
}a[N];

bool cmp(node b,node c){return b.x > c.x;}
bool cmp1(node b,node c){return b.y > c.y;}
bool cmp2(node b,node c){return b.z > c.z;}

int flag = 0;
/*我是CQ-S00369 luogu 用户名 xf20280111 
我是蒟蒻，第一题都不会，只有5分。
我想上迷惑行为大赏，这是退役前必做的事。 
突然觉得旁边的老哥长得挺帅的 
*/ 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;cin >> T;
	while(T--){
		int n,sum1 = 0,sum2 = 0,sum3 = 0;cin >> n;
		for (int i = 1;i <= n;i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			if (a[i].y != 0 or a[i].z != 0) flag = 1;
			a[i].id = i;
		}
		if (flag == 0){
			sort(a + 1,a + n + 1,cmp);
			for (int i = 1;i <= n / 2;i++) sum1 += a[i].x;
			cout << sum1;
			break;
		}
		sort(a + 1,a + n + 1,cmp);
		for (int i = 1;i <= n / 2;i++)sum1 += a[i].x;
		for (int i = n / 2 + 1;i <= n;i++) sum1 += max(a[i].y,a[i].z);
		
		sort(a + 1,a + n + 1,cmp1);
		for (int i = 1;i <= n / 2;i++) sum2 += a[i].y;
		for (int i = n / 2 + 1;i <= n;i++) sum2 += max(a[i].x,a[i].z);
		
		sort(a + 1,a + n + 1,cmp2);
		for (int i = 1;i <= n / 2;i++) sum3 += a[i].z;
		for (int i = n / 2 + 1;i <= n;i++) sum3 += max(a[i].x,a[i].y);
		
		cout << max(sum1,max(sum2,sum3)) << '\n';

	}
	return 0;
}
