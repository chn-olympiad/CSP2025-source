#include <bits/stdc++.h>
using namespace std;
int n,t,a1[110001],a2[110001],a3[110001],sum=0,ans[110001],i=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int p = 1;p <= t;p++){
		cin >> n;
		for(int o = 1;o <= n;o++){
			cin >> a1[o] >> a2[o] >> a3[o];
			sum+=max(a1[o],max(a2[o],a3[0]));
		}
		ans[i]=sum;
		sum=0;
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(a3,0,sizeof(a3));
		i++;
	}
	for(int j = 1;j < i;j++)
		cout << ans[j] << endl;
	return 0;
}
 
