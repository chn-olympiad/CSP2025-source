#include<bits\stdc++.h>
using namespace std;
long long s[100010][3],ans=0,c[3]={0},n,m,anss=0;
void dfs(int x){
	if(x==m+1){
		if(ans>anss){
			anss=ans;
		}
		return ;
	}
	for(int i=1;i<=3;i++){
		c[i]++;
		ans+=s[x][i];
		if(c[i]<=m/2){
			dfs(x+1);
		}
		ans-=s[x][i];
		c[i]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>s[i][1]>>s[i][2]>>s[i][3];
		}
		m=n;ans=0;c[1]=0;c[2]=0;c[3]=0;anss=0;
		dfs(1);
		cout<<anss<<endl;
	}
	return 0;
}
