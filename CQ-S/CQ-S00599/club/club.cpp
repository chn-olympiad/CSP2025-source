#include<bits/stdc++.h>
using namespace std;using ll=long long;
int rd(int x=0,char c=getchar()){int f=1;while(!isdigit(c))f=(c^'-'?1:-1),c=getchar();while(isdigit(c))x=x*10+(c^48),c=getchar();return x*f;}
const int N=1e5+5;
int n;
int c[3];
int a[N][3];
void solve(){
	n=rd();
	c[0]=c[1]=c[2]=0;
	int t=0,ans=0;
	vector<int> can[3];
	for(int i=1;i<=n;i++){
		a[i][0]=rd(),a[i][1]=rd(),a[i][2]=rd();
		int mx=max(a[i][0],max(a[i][1],a[i][2])),mt;
		if(a[i][0]==mx)mt=max(a[i][1],a[i][2]),c[0]++,can[0].push_back(mx-mt);
		else if(a[i][1]==mx)mt=max(a[i][0],a[i][2]),c[1]++,can[1].push_back(mx-mt);
		else mt=max(a[i][0],a[i][1]),c[2]++,can[2].push_back(mx-mt);
		ans+=mx;
	}
	int id=-1;
	if(c[0]>n/2)id=0;
	if(c[1]>n/2)id=1;
	if(c[2]>n/2)id=2;
	if(id==-1){
		printf("%d\n",ans);
		return;
	}
	sort(can[id].begin(),can[id].end());
	int x=c[id]-n/2;
	for(int i=0;i<x;i++)ans-=can[id][i];
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=rd();while(t--)solve();
	return 0;
}

