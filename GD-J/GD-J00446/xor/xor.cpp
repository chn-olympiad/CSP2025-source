#include<bits/stdc++.h>
#define ll long long
using namespace std;
int k,n,a[500010],ans,t,sum[500010],l;
map<int,int>m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]^a[i];
	for(int i=1;i<=n;i++){
		t^=a[i];
		if(m[t^k]||t==k) t=0,ans++,m.clear();
		m[t]=1;
	}
	cout<<ans;
}
/*
//freopen("xor.in","r",stdin);
//freopen("xor.out","w",stdout);
RP += INF
I am 593499!!
Wo Yao Shang GD Mi Huo Xing Wei Da Shang!!
Bu Que Ding Neng Fou Da Zhong Wen,
Suo Yi An Jiu Da Ying Wen.
Qiu Gei Ge J 1= S 1=
*/
