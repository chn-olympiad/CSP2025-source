#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,x,y) for(int i=x;i<=y;i++)
const int M=100101;
const int inf=1e9+7;
int n,m,ans;
bool dis[M];
string a[M][2],b,c;
void dfs(string x){
	if(x==c) ans++;
	else{
		For(i,1,b.size()){
			For(j,1,n){
				if(dis[j]) continue;
				if(a[j][0].size()+i-1>b.size()) continue;
				bool tmp=0;
				For(k,1,a[j][0].size()){
					if(x[i+k-2]!=a[j][0][k-1]){
						tmp=1;
						break;
					}
				}
				if(!tmp){
					string o=x;
					For(k,1,a[j][0].size()){
						o[i+k-2]=a[j][1][k-1];
					}
//					cout<<x<<j<<o<<"\n";
					dis[j]=1;
					dfs(o);
					dis[j]=0;
				}
			}
		}
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	For(i,1,n) cin>>a[i][0]>>a[i][1];
	For(i,1,m){
		ans=0;
		cin>>b>>c;
		dfs(b);
		printf("%d\n",ans);
	}
	
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
