#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,a[N][3],Maxid;
long long sum;
vector<int>e[4];
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x;
}
void clear(){
	n=read();
	sum=Maxid=0;
	for(int i=0;i<4;i++){
		e[i].clear();
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	t=read();
	while(t--){
		clear();
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++)
				a[i][j]=read();
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				e[0].emplace_back(i);
				sum+=a[i][0];
			}
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				e[1].emplace_back(i);
				sum+=a[i][1];
			}
			else{
				e[2].emplace_back(i);
				sum+=a[i][2];
			}
		}
		if(e[1].size()>=e[0].size())
			Maxid=1;
		if(e[2].size()>=e[Maxid].size())
			Maxid=2;
		if((int)e[Maxid].size()<=n/2){
			printf("%lld\n",sum);
			continue;
		}
		int cut=e[Maxid].size()-(n/2);
		for(int v:e[Maxid]){
			e[3].emplace_back(a[v][Maxid]-max(a[v][(Maxid+1)%3],a[v][(Maxid+2)%3]));
		}
		sort(e[3].begin(),e[3].end());
		for(int v:e[3]){
			if(!cut)
				break;
			cut--;
			sum-=v;
		}
		printf("%lld\n",sum);
	}
	return 0;
}