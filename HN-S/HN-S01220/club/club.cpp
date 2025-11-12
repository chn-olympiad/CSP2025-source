#include<bits/stdc++.h>
using namespace std;
int t,n,h,ans;
int g[100010][100010],a,b,c;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t); 
	while(t--){
		ans = 0;
		scanf("%d",&n);
		h = n / 2;
		a = 0;
		b = 0;
		c = 0;
		for(int i = 1;i <= n;i++){
			cin>>g[1][i]>>g[2][i]>>g[3][i];
			ans+=max(g[1][i],max(g[2][i],g[3][i])); 
		}
	}
	cout<<ans;
	return 0;
} 
