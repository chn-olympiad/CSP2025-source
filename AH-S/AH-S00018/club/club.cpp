#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template <class Miaowu>
inline void in(Miaowu &x){
	char c;x=0;bool f=0;
	for(c=getchar();c<'0'||c>'9';c=getchar())f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
const int N=1e5+5;
int T,n,a[N][3],b[N],qwq[N],cnt[3];
int main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	for(cin>>T;T;T--){
		in(n);
		for(int i=1;i<=n;i++)for(int j=0;j<3;j++)in(a[i][j]);
		int sum=cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++)qwq[i]=max(max(a[i][0],a[i][1]),a[i][2]),sum+=qwq[i];
		for(int i=1;i<=n;i++)cnt[b[i]=(qwq[i]==a[i][0]?0:(qwq[i]==a[i][1]?1:2))]++;
		if(max(max(cnt[0],cnt[1]),cnt[2])<=(n>>1)){printf("%d\n",sum);continue;}
		int k=(cnt[1]>(n>>1)?1:(cnt[0]>(n>>1)?0:2));
		vector<int>vc;
		for(int i=1;i<=n;i++)if(b[i]==k){
			int mn=1e9;
			for(int j=0;j<3;j++)if(j!=k)mn=min(mn,a[i][k]-a[i][j]);
			vc.push_back(mn);
		}
		stable_sort(vc.begin(),vc.end());
		for(int i=0;i<cnt[k]-(n>>1);i++)sum-=vc[i];
		printf("%d\n",sum);
	}
	return 0;
}