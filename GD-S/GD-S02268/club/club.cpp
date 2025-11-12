#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[5] , bumen[5] , bu[5] , man = 0 , man1 = 0 , man2 = 0;
ll b[5];

int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	
	int t;
	cin >> t;
	ll n;
	for (int i = 1 ; i <= t ; i++){
		cin >> n;
		man = 0;
		for (int i = 0 ; i < n ; i++){
			cin >> a[0] >> a[1] >> a[2];
			ll b[5];//保存a的数据 
			b[0] = a[0] , b[1] = a[1] , b[2] = a[2];
			sort(a , a + 3);//将a排序 
			
			for (int i = 0 ; i < 3 ; i++){//判断每一个a的数据代表哪一个部门 
				if (a[2] == b[i]){//最大满意度 
					bu[0] = i;
				}
				if (a[1] == b[i]){//第二 
					bu[1] = i ;
				}
				if (a[2] == b[i]){//最小 
					bu[2] = i;
				}
			}
			
			if (bumen[bu[0]] < n / 2){
				bumen[bu[0]]++;
				man += a[2];
				man1 += a[1];
				man2 += a[0]; 
			} 
			else if (bumen[bu[1]] < n / 2){
				bumen[bu[1]]++;
				man += a[1];
				man1 += a[2];
				man2 += a[1];
			}
			else if (bumen[bu[0]] < n / 2){
				bumen[bu[2]]++;
				man += a[0];
				man1 += a[0];
				man2 += a[2];
			}
		}	
		cout << max(man , max(man1 , man2) << '\n';
	}
	return 0;
}
