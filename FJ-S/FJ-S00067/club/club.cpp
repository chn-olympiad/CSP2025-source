#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][4],ch[N],cc[4],ans;
vector<int> vec;
int read(){
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int x=0;
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
} 
void solve(){
	n=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) a[i][j]=read();
	for(int i=1;i<=3;i++) cc[i]=0;
	ans=0;
	for(int i=1;i<=n;i++){
		ch[i]=0;
		for(int j=1;j<=3;j++) if(a[i][j]>=a[i][ch[i]]) ch[i]=j;
		cc[ch[i]]++,ans+=a[i][ch[i]];
	}
	int flag=0;
	for(int i=1;i<=3;i++) if(cc[i]>n/2) flag=i;
	if(!flag){printf("%d\n",ans);return;}
	vec.clear();
	for(int i=1;i<=n;i++){
		if(ch[i]!=flag) continue;
		int mx=0;
		for(int j=1;j<=3;j++) if(j!=ch[i]) mx=max(mx,a[i][j]);
		vec.push_back(mx-a[i][ch[i]]);
	}
	sort(vec.begin(),vec.end(),greater<int>());
	for(int i=0;i<cc[flag]-n/2;i++) ans+=vec[i];
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--) solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
