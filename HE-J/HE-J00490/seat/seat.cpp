#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> awa;
int qwq[12][12];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int a;
	for(int i=1,ans;i<=n*m;i++){
		scanf("%d",&ans);
		if(i==1) a=ans;
		awa.push_back(ans);	
	}
	sort(awa.begin(),awa.end());
	int xb=awa.size()-1;
	for(int i=1;i<=n;i++){
		if(i%2==1)for(int j=1;j<=n;j++)qwq[i][j]=awa[xb--];
		else for(int j=n;j>=1;j--)qwq[i][j]=awa[xb--];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(qwq[i][j]==a){
				printf("%d %d",i,j);
				return 0;
			}
	return 0;
}//RP++
