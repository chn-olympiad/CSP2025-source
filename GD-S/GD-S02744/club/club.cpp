#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 1e5+10;
int n,m;
int cnt[5];
int f[N],id[N];
struct node{
	int num,id;
}tmp[5];
inline bool cmp(node x,node y){
	return x.num<y.num;
}
int num[N],idx;

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int q1,q2,q3;
		int ans = 0;
		for(int i=1;i<=n;i++){
			cin>>q1>>q2>>q3;
			tmp[1] = {q1,1},tmp[2] = {q2,2},tmp[3] = {q3,3};
			sort(tmp+1,tmp+4,cmp);
			f[i] = tmp[3].num-tmp[2].num;
			id[i] = tmp[3].id;
			cnt[id[i]]++;
			ans += tmp[3].num;
		}
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2){
				for(int j=1;j<=n;j++){
					if(id[j]==i){
						num[++idx] = f[j];
					}
				}
				sort(num+1,num+idx+1);
				int rest = cnt[i]-(n/2);
				for(int i=1;i<=rest;i++){
					ans -= num[i];
				}
				break;
			}
		}
		cout<<ans<<endl;
		
		idx = 0;
		for(int i=1;i<=3;i++){
			cnt[i] = 0;
		}
	}
	
	return 0;
}
