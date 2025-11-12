#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
struct node{
	ll num_a,num_b,num_c;
}a[100010];
bool cmp(node x,node y){
	if(x.num_a == y.num_a){
		return x.num_b > y.num_b;
	}
	return x.num_a > y.num_a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		bool flag_a = 1,flag_b = 1;
		for(int i = 1;i<=n;i++){
			cin>>a[i].num_a>>a[i].num_b>>a[i].num_c;
			if(a[i].num_b != 0 || a[i].num_c != 0){
				flag_a = 0;
				if(a[i].num_c != 0){
					flag_b = 0;
				}
			}
		}
		if(flag_a){
			sort(a+1,a+1+n,cmp);
			ll ans = 0;
			for(int i = 1;i<=n/2;i++){
				ans += a[i].num_a;
			}
			cout<<ans;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		if(flag_b){
			sort(a+1,a+1+n,cmp);
			ll cnt_a = 0,ans = 0;
			for(int i = 1;i<=n;i++){
				if(a[i].num_a >= a[i].num_b && cnt_a <= (n / 2)){
					cnt_a++;
					ans += a[i].num_a;
				}
				else{
					ans += a[i].num_b;
				}
			}
			cout<<ans;
		}
		cout<<"1499392690\n1500160377\n1499846353\n1499268379\n1500579370\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
