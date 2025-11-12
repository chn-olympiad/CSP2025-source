#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define N 100005
using namespace std;
struct node{
	int a_1,a_2,a_3;
}a[N];
bool cmp(node x, node y){
	return x.a_1 > y.a_1; 
}
int o_1[10001],o_2[10001],o_3[10001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i = 1; i <= n; i++){
			cin>>a[i].a_1>>a[i].a_2>>a[i].a_3;
		}
		int maxn_2 = -1;
		int maxn_3 = -1;
		for(int i = 1; i <= n; i++){
			maxn_2 = max(maxn_2,a[i].a_2);
			maxn_3 = max(maxn_3,a[i].a_3);
		}
		if(maxn_2 == 0 && maxn_3 == 0){
			int cnt = 0;
			sort(a+1,a+1+n,cmp);
			for(int i = 1; i <= n/2; i++){
				cnt+=a[i].a_1;
			}
			cout<<cnt;
			continue;
		}
		if(n==1){
			cout<<max({a[1].a_1,a[1].a_2,a[1].a_3});
			continue;
		}
		if(n==2){
			int aa = a[1].a_1+a[2].a_2;
			int ab = a[1].a_1+a[2].a_3;
			int ac = a[1].a_2+a[2].a_1;
			int ad = a[1].a_2+a[2].a_3;
			int ae = a[1].a_3+a[2].a_2;
			int af = a[1].a_3+a[2].a_1;
			cout<<max({aa,ab,ac,ad,ae,af});
		}
		if(n==3){
			int aa = a[1].a_1+a[2].a_2+a[3].a_3;
			int ab = a[1].a_1+a[2].a_3+a[3].a_2;
			int ac = a[1].a_2+a[2].a_1+a[3].a_3;
			int ad = a[1].a_2+a[2].a_3+a[3].a_1;
			int ae = a[1].a_3+a[2].a_2+a[3].a_1;
			int af = a[1].a_3+a[2].a_1+a[3].a_2;
			int ans = max({aa,ab,ac,ad,ae,af});
			cout<<ans;
			continue;
		}
		if(n==4){
			ll ans = -1;
			int h = n/2;
			for(int i = 1; i <= pow(3,n); i++){
				ll cnt = 0;
				int j = i;
				int aa = 0;
				int ab = 0;
				int ac = 0;
				int num = n;
				while(num>0){
					if(j%3 == 0){
						aa++;
						o_1[aa] = num;
					}
					else if(j%3 == 1){
						ab++;
						o_2[ab] = num;
					}
					else if(j%3 == 2){
						ac++;
						o_3[ac] = num;
					}
					j/=3;
					num--;
				}
				if(aa > h || ab > h || ac > h){
					continue;
				}
				for(int i = 1; i <= aa; i++){
					cnt += a[o_1[i]].a_1;
				}
				cout<<endl;
				for(int i = 1; i <= ab; i++){
					cnt += a[o_2[i]].a_2;
				}
				cout<<endl;
				for(int i = 1; i <= ac; i++){
					cnt += a[o_3[i]].a_3;
				}
				cout<<endl;
				ans = max(ans,cnt);
			}
			cout<<ans;
			continue;
		}
	}
	
	
	
	return 0;
}
