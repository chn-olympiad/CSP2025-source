#include<bits/stdc++.h>
#define ll long long
using namespace std;
int vis[100010],n;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s,n=s.size();
	for(int i=0;i<n;i++)
		vis[s[i]-48]++;
	for(int i=9;i>=0;i--)
		while(vis[i]) cout<<i,vis[i]--;
}
/*
//freopen("number.in","r",stdin);
//freopen("number.out","w",stdout);
RP += INF
I am 593499!!
Wo Yao Shang GD Mi Huo Xing Wei Da Shang!!
Bu Que Ding Neng Fou Da Zhong Wen,
Suo Yi An Jiu Da Ying Wen.
Qiu Gei Ge J 1= S 1=
*/
