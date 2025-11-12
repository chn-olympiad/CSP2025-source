#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,k,z,x,s,p,ans,maxn[100005],y;
int a[100005][3];
int tg[3];
priority_queue<int> hp;
void read(int &x){
	char ch=getchar();
	x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return ;
}
int main(){
	//club
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int tz;
	read(tz);
	while(tz--){
		ans=0;
		tg[0]=0,tg[1]=0,tg[2]=0;
		read(n);
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++)
				read(a[i][j]);
			maxn[i]=0;
			if(a[i][1]>a[i][maxn[i]]) maxn[i]=1;
			if(a[i][2]>a[i][maxn[i]]) maxn[i]=2;
			ans+=a[i][maxn[i]],tg[maxn[i]]++;
		}
		x=-1;
		for(int j=0;j<3;j++)
			if(tg[j]*2>n) x=j;
		if(x!=-1){
			while(hp.size()>0) hp.pop();
			for(int i=1;i<=n;i++){
				if(maxn[i]==x){
					y=0;
					for(int j=0;j<3;j++){
						if(j==x) continue;
						y=max(a[i][j],y);
					}
					hp.push(y-a[i][x]);
				}
			}
			while(tg[x]*2>n)
				tg[x]--,ans+=hp.top(),hp.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
} 
