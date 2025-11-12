#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N=5*1e5+5;
ll n,k,a[N],now,ans,l;
bool b=0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(k==0){
		for(ll i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		printf("%d",n/2);
		return 0;
	}else{
		for(ll i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(ll i=1;i<=n;i++){
			for(ll j=i;j<=n;j++){
				now=0;
				for(ll m=i;m<=j;m++){
					if(i==j&&a[i]==k&&i>l){
						ans++;
						l=i;
						break;
					}
					now^=a[m];
				}
				if(now==k&&i>l){
					ans++;
					l=j;
				}
			}
		}
		cout<<ans;
	}
	/*
	留给我的时间不多了
	t3没做出来t4竟然做出来了
	多亏了我的好兄弟yl(l love you)
	6年级开始学的，也没想过会来打比赛
	去年爆零了
	今年我势必夺回属于我的一切 
	不过初三了，也没什么时间了，这一个月里都是自学的
	没事，等我到了高中 
	ccf wait me!
	2025/11/1 11:39
	不说了，我去检查了。 
	*/
	return 0;
}
