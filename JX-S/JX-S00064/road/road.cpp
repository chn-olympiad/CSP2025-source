#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int v;
	int w;
};
vector<node>q[10005];
int c[15],a[15][10005];
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u;node p;
		cin>>u>>p.v>>p.w;
		q[u].push_back(p);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
}

/*
2.22pm->22.22pm  t+8h

written by LX_cpp

2025/11/1 14:18 kaoqian
zhe shi zui hou yi chang le ba?wo chuzhong jie duan de csp.
zhe chang bisai gai kai shi le.
gang shang gao zhong de shi hou wo mingming haidui youxi ting gan xing qu de.
xianzai you shi hou ji shi gei wangluo ye bu xiang wan.
shi wo da le ma?
hai shi dan chun de mei ai le?
jing nian bi qu nian da bi sai de shi jian wan le qi tian.
xiang dang chu, xue ji suan ji ke neng zhen de shi wei le da you xi :)
dan xue le siwu nian ye xue chu gan qing lai le,"LX" zhe ge id ye pei le wo hao duo nian
yi ji"kcx_233", wo de Minecraft id,luogu xiao hao id
5e04 de ren hai zai niandao:"pian fen guo yang li,bao li TLE",ta tingqilai haoxiao
xiangwo gang kai shi xue de yang zi,yin gai zhi xue le yiliang nian ba?

2025/11/1 14:25 
xing qi lai yi weixue zhang recollecter(ru guo mei ji cuo de hua) yangfei long
qian nian de noi cu jiangxi shendui duizhang;
kaoqian 3min , zai ci biao shi ji nian yu zhu fu,yan qi 2026gaokao rp++


2025/11/1 14:36
T1 you dian nan.

2025/11/1 16:00
mei yi dian xiang fa,xianda qi ta ji ti bao li ba.

2025/11/1 16:14
jiu wo......

2025/11/1 16:16
zhi neng qi dao mei you hack le...... yj30

2025/11/1 16:45
baoli+jiyihua...... yj60

2025/11/1 16:54
shu dao yong shi fang hen shao...... zui xiao shen cheng shu wo hen ni!!!!!!!

2025/11/1 16:56
er wei dp.

2025/11/1 17:06
hui zha.

2025/11/1 17:26
fuck.
*/