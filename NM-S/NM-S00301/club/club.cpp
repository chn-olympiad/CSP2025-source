#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][4],m[4][200010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int i,j=0;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		j=0;
		memset(a,0,sizeof a);
		memset(m,0,sizeof m);
		for(i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			int mx=max(a[i][1],max(a[i][2],a[i][3]));
			if(mx==a[i][1])
				m[1][++m[1][0]]=mx-max(a[i][2],a[i][3]);
			if(mx==a[i][2])
				m[2][++m[2][0]]=mx-max(a[i][1],a[i][3]);
			if(mx==a[i][3])
				m[3][++m[3][0]]=mx-max(a[i][2],a[i][1]);
			j+=mx;
		}
		sort(&m[1][1],&m[1][m[1][0]]+1,cmp);
		sort(&m[2][1],&m[2][m[2][0]]+1,cmp);
		sort(&m[3][1],&m[3][m[3][0]]+1,cmp);
		int Mx=n/2,tom=0;
		while(m[1][0]>Mx)tom+=m[1][m[1][0]--];
		while(m[2][0]>Mx)tom+=m[2][m[2][0]--];
		while(m[3][0]>Mx)tom+=m[3][m[3][0]--];
		j-=tom;
		cout<<j<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
