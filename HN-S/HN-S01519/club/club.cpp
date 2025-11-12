#include<bits/stdc++.h>
using namespace std;
int read(){
	int x,c;
	while((c=getchar())<'0'||c>'9');
	x=c^48;
	while((c=getchar())>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48);
	return x;
}
int n,a,b,c,x;long long ans;
vector<int> s[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		for(int i=0;i<3;i++)
			s[i].clear();
		n=read();ans=0;
		for(int i=1;i<=n;i++){
			a=read();b=read();c=read();
			ans+=(x=max(max(a,b),c));
			if(a==x)
				s[0].push_back(max(b,c)-a);
			else if(b==x)
				s[1].push_back(max(a,c)-b);
			else
				s[2].push_back(max(a,b)-c);
		}
		for(int i=0;i<3;i++){
			sort(s[i].begin(),s[i].end());
			while(s[i].size()>(n>>1)){
				ans+=s[i].back();
				s[i].pop_back();
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}