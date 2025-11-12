#include<bits/stdc++.h>
using namespace std;
int T;
int n;
struct mi{
	int a1,a2,a3;
}a[100010];
bool cmp1(mi x,mi y){
	return x.a1 > y.a1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		sort(a + 1,a + n + 1,cmp1);
		int ans = 0;
		for(int i = 1;i <= n / 2;i++){
			ans += a[i].a1;
		}
		cout<<ans<<endl;
	}
	return 0;
}

