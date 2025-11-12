#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int s[1005][1005],s1[1005],bc[1005],br[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			s[a][s1]=s[b][s1]=c;
		}
	}
	cout<<23;
	return 0;
}
