#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
using namespace std;
int Time=clock();
bool mst;
const int N=1e5+5;
struct st{
	int pos,v;
	bool operator <(st oth){
		return v>oth.v;
	}
};
st A[N][4];
int T,n,d[N],cnt[4],td[N];
bool med;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		int ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				A[i][j].pos=j;
				cin>>A[i][j].v;
			}
			sort(A[i]+1,A[i]+1+3);
			int p=A[i][1].pos;
			d[i]=p,cnt[p]++,ans+=A[i][1].v;
		}
		for(int i=1;i<=3;i++)
			if(cnt[i]>n/2){
				int len=0;
				for(int j=1;j<=n;j++)
					if(d[j]==i)  td[++len]=A[j][1].v-A[j][2].v;
				sort(td+1,td+1+len);
				for(int j=1;j<=len-n/2;j++)
					ans-=td[j];
				break;
			}
		cout<<ans<<'\n';
	}
	// cerr<<"Time:"<<1.0*(clock()-Time)/CLOCKS_PER_SEC<<"s\n";
	// cerr<<"Memory:"<<1.0*(&med-&mst)/1024.0/1024.0<<"MB\n";
	return 0;
}