#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read(){
	int x=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1),x+=(c-48),c=getchar();
	return x;
}
vector<int> club[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		ll ans=0;
		int op=0,n=read(),cnt[4]={};
		for(int i=1;i<=n;i++){
			int a=read(),b=read(),c=read();
			if(a>=b && a>=c){
				ans+=a,cnt[1]++;
				if(b>=c) club[1].push_back(a-b);
				else club[1].push_back(a-c);
			}else if(b>=a && b>=c){
				ans+=b,cnt[2]++;
				if(a>=c) club[2].push_back(b-a);
				else club[2].push_back(b-c);
			}else{
				ans+=c,cnt[3]++;
				if(a>=b) club[3].push_back(c-a);
				else club[3].push_back(c-b);
			}
		}
		for(int i=1;i<=3;i++) if(cnt[i]>n/2) op=i;
		if(op){
			int x=0;
			sort(club[op].begin(),club[op].end());
			while(cnt[op]>n/2)
				cnt[op]--,ans-=club[op][x],x++;
		}
		for(int i=1;i<=3;i++) club[i].clear();
		cout<<ans<<"\n";
	}
	return 0;
} 
