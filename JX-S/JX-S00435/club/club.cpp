#include<bits/stdc++.h>
using namespace std;
int qw;
int a[1000005][5];
int n;
long long jk(int op,int x,int y,int z){
	if(op>n)
		return 0;
	long long ans = 0;
	if(x+1<=n/2)
		ans =max( ans , a[op][1] + jk(op+1,x+1,y,z) );
	if(y+1<=n/2)
		ans =max( ans , a[op][2] + jk(op+1,x,y+1,z) );
	if(z+1<=n/2)
		ans =max( ans , a[op][3] + jk(op+1,x,y,z+1) );
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&qw);
	while(qw--){
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		cout<<jk(1,0,0,0)<<endl;
	}
	return 0;
}
