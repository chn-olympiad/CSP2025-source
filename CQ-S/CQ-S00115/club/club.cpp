#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
using namespace std;
namespace Yukina{
	inline int read(){
		int ans=0,w=1;
		char ch=getchar();
		while(ch<48||ch>57){
			if(ch=='-')w=-1;
			ch=getchar();
		}
		while(ch>=48&&ch<=57){
			ans=(ans<<1)+(ans<<3)+ch-48;
			ch=getchar();
		}
		return w*ans;
	}
	int T;
	int n;
	int a[100005][5]; 
	int cnt[5];
	vector<int>vec[5];
	int main(){
		T=read();
		while(T--){
			memset(a,0,sizeof a),memset(cnt,0,sizeof cnt);
			vec[1].clear(),vec[2].clear(),vec[3].clear(); 
			n=read();
			for(int i=1;i<=n;i++)a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
			ll ans=0;
			for(int i=1;i<=n;i++){
				int maxx=max({a[i][1],a[i][2],a[i][3]});
				if(a[i][1]==maxx)++cnt[1],ans+=a[i][1],vec[1].push_back(maxx-max(a[i][2],a[i][3]));
				else if(a[i][2]==maxx)++cnt[2],ans+=a[i][2],vec[2].push_back(maxx-max(a[i][1],a[i][3]));
				else ++cnt[3],ans+=a[i][3],vec[3].push_back(maxx-max(a[i][1],a[i][2]));
			}
			if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
				cout<<ans<<'\n';
				continue;
			}
			if(cnt[1]>n/2){
				sort(vec[1].begin(),vec[1].end());
				for(int i=0;i<cnt[1]-n/2;i++)ans-=vec[1][i];
			} 
			else if(cnt[2]>n/2){
				sort(vec[2].begin(),vec[2].end());
				for(int i=0;i<cnt[2]-n/2;i++)ans-=vec[2][i];
			}
			else{//3
				sort(vec[3].begin(),vec[3].end());
				for(int i=0;i<cnt[3]-n/2;i++)ans-=vec[3][i];
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	return Yukina::main();
}
/*
14:40 AC
3MB
*/
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
