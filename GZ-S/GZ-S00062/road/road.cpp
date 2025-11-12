//GZ-S00062 刘祉杙 贵阳市清华中学                                                                                                                                                                                                                                                                   
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e6+5;
ll n,m,k;
ll l,r,vl,ans;
ll vc; 
ll v[M];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>l>>r>>vl;
	}
	for(ll i=1;i<=k;i++){
		cin>>vc;
		ans+=vc;
		for(ll j=1;j<=n;j++) cin>>v[j];
	}
	cout<<ans<<endl;
	
	return 0;
}
/*
塞纳河畔 左岸的咖啡 
我手一杯 品尝你的美 
留下唇印的嘴 噢噢噢噢 
花店玫瑰 名字写错谁 
告白气球 飘向对面街 
微笑在天上飞 耶 
你说你有点难追 想让我知难而退 
礼物不需挑最贵 只要香榭的落叶 
哦营造浪漫的约会 不害怕搞砸一切 
拥有你就拥有全世界 
亲爱的 爱上你 从那天起 甜蜜的很轻易 
亲爱的 别任性 你的眼睛 再说我愿意~ 
*/ 
