#include<bits/stdc++.h>
#define int long long
namespace FastIO{
	template<typename T>inline void read(T &x){
		x=0;int f=1;char c=getchar();
		for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
		for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);x*=f;
	}
	template<typename T,typename...Args>
	inline void read(T &x,Args&...args){
		read(x);
		read(args...);
	}
	template<typename T>void print(T x){
		if(x<0)x=-x,putchar('-');
		if(x>9)print(x/10);
		putchar((x%10)^48);
	}
}
using namespace FastIO;
using namespace std;
const int N=1e5+5;
int t,n,cnt[5],ans;
struct node{
	int typ,num;
}a[N][5];
bool cmp(node a,node b){
	return a.num>b.num;
}
set<pair<pair<int,int>,int>>S;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(t);
	while(t--){
		memset(cnt,0,sizeof cnt);
		S.clear();
		ans=0;
		read(n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				read(a[i][j].num);
				a[i][j].typ=j;
			}
			sort(a[i]+1,a[i]+4,cmp);
		}
		for(int i=1;i<=n;i++){
			S.insert(make_pair(make_pair(a[i][1].num-a[i][2].num,a[i][2].num-a[i][1].num),i));
		}
		for(auto i=S.rbegin();i!=S.rend();i++){
			auto now=*i;
			int id=now.second;
			for(int j=1;j<=3;j++){
				int typ=a[id][j].typ;
				if(cnt[typ]<n/2){
					ans+=a[id][j].num;
					cnt[typ]++;
					break;
				}
			}
		}
		print(ans);
		cout<<'\n';
	} 
	return 0;
}