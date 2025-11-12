#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1e5+7;
int T,n,m;
int ans,a[N][3];
vector<int> C[3];
void init(){
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++) a[i][j]=0;
	for(int j=0;j<3;j++) C[j].clear();
	n=ans=0; m=-1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int k=-1,p=-1;
			for(int j=0;j<3;j++){
				scanf("%d",&a[i][j]);
				if(k<0||a[i][k]<a[i][j]) p=k,k=j;
				else if(p<0||a[i][p]<a[i][j]) p=j;
			}
			C[k].push_back(a[i][k]-a[i][p]);
			ans+=a[i][k];
		}
		for(int j=0;j<3;j++) if(2*C[j].size()>n) m=j;
		if(m==-1){
			printf("%d\n",ans);
			continue;
		}
		sort(C[m].begin(),C[m].end());
		for(int i=0;i<C[m].size()-n/2;i++) ans-=C[m][i];
		printf("%d\n",ans);
	}
	return 0; 
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
