//wait to test
#include<bits/stdc++.h>
#define int long long
#define MX 100005
using namespace std;int read();
int n,a[MX][5],m,b[MX],res,cnt;
vector<int> v[5];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();while(T--){
		n=read();res=m=0;
		for(int j=1;j<=3;j++)
			v[j].clear();
		for(int i=1;i<=n;i++){
			int cse=1;b[i]=0;
			for(int j=1;j<=3;j++){
				a[i][j]=read();
				if(a[i][j]>=a[i][cse]) cse=j;
			}res+=a[i][cse];
			v[cse].emplace_back(i);
		}cnt=0;
		for(int j=1;j<=3;j++){
			int w=v[j].size();
			if(w>(n/2)) cnt=j;
		}
		if(cnt){
			m=0;
			for(auto i:v[cnt]){
				int w=0;
				for(int j=1;j<=3;j++){
					if(j==cnt) continue;
					w=max(w,a[i][j]);
				}b[++m]=a[i][cnt]-w;
			}sort(b+1,b+1+m);
			m-=(n/2);
			for(int i=1;i<=m;i++)
				res-=b[i];
		}
		printf("%lld\n",res);
	}
	return 0;
}
int read(){
	int Ca=0,Cf=1;char Cr=' ';
	while(Cr<'0' || Cr>'9'){Cr=getchar();if(Cr=='-'){Cf=-Cf;}}
	while(Cr>='0' && Cr<='9'){Ca=Ca*10+(Cr-'0');Cr=getchar();}
	return Ca*Cf;
}
