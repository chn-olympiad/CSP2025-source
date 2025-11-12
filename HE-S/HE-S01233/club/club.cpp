#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int a[100005][5];
vector <int> clb[5];
priority_queue <int> aft;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		for(int i=1;i<=3;i++)	clb[i].clear();
		int n;
		scanf("%d",&n);
		int limitmem=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)	scanf("%d",&a[i][j]);
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3])	clb[1].push_back(i);
			else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3])	clb[2].push_back(i);
			else	clb[3].push_back(i);
		}
		int ovNo=0;
		for(int i=1;i<=3;i++)	if(clb[i].size()>limitmem)	ovNo=i;
		if(ovNo){
			int goout=clb[ovNo].size()-limitmem;
			for(int now:clb[ovNo]){
				int secpref=0;
				for(int i=1;i<=3;i++)	if(i!=ovNo)	secpref=max(secpref,a[now][i]);
				aft.push(a[now][ovNo]-secpref);
				if(aft.size()>goout)	aft.pop();
			}
		}
		int res=0;
		for(int i=1;i<=3;i++){
			for(int now:clb[i])	res+=a[now][i];
		}
		while(!aft.empty()){
			res-=aft.top();
			aft.pop();
		}
		printf("%d\n",res);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
