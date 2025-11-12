//GZ-S00139 贵阳市第三实验中学 宋诗迪 
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void Solve_time(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}
int n;
const int N=1e5+5;
struct node{
	ll v,id;
	bool vis;
}one[N],two[N],three[N];
bool cmp(node x,node y){
	return x.v>y.v;
}
ll find(ll x){
	int flag=0;
	for(int i=1;i<=n;i++){
		if(one[i].v==x){
			flag=1;
			return 0;
		}
		if(two[i].v==x){
			flag=2;
			return 0;
		}
		else{
			flag=3;
			return 0;
		}
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	Solve_time();
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>one[i].v>>two[i].v>>three[i].v;
			one[i].id=i;
			two[i].id=i;
			three[i].id=i;
		}
		sort(one+1,one+1+n,cmp);
		sort(two+1,two+1+n,cmp);
		sort(three+1,three+1+n,cmp);
		int maxn=n/2;
		ll ans=0;
		for(int i=1;i<=3;i++)
			//蒻笈无疑,越写越懵
			//猜测为动态规划 
			for(int j=1;i<=n;j++)
				for(int k=1;k<=maxn;k++){
					if(k[i].id!=0){
						ans+=k[i].v;
						k[i].id=0; 
					}
				}
		cout<<ans<<"\n";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
//Ren5Jie4Di4Ling5%
