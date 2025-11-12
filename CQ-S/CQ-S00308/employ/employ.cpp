#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans,z[501],p[20],f[20];
string s;
void upp(ll x){
	if(x>=n){
		ll ss=0,us=0;
		for(ll i=1;i<=n;i++){
			if(z[p[i]]<=ss) ss++;
			else{
				if(s[i-1]=='1') us++;
				else ss++;	
			}
		}
		if(us>=m) ans++;
	}
	else{
		x++;
		for(ll i=1;i<=n;i++){
			if(f[i]==0){
				p[x]=i;
				f[i]=1;
				upp(x);
				f[i]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>n>>m>>s;
	for(ll i=1;i<=n;i++) cin>>z[i];
	
		upp(0);
		cout<<ans;
	return 0;
} 

/*
如果有人看见了，那恭喜你看见了

没事，反正已经退役了-8，27 


在三分钟内想出了T1,原本以为成了，可惜

后面的题怎么这么难啊 


可惜了，离她更远了

我在代码中藏了她的名字，快来找找吧 






































哎，曾经的我怎么没有抓住呢，


也成了鲁迅口中怀古伤今的人了 
*/
