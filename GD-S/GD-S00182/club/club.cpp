#include <bits/stdc++.h>

using namespace std;

const int maxn=1e5+5;
vector<int> vec[4];
int a[maxn][5],b[maxn][5];

bool cmp(int x,int y){
	return a[x][b[x][1]]-a[x][b[x][2]]>a[y][b[y][1]]-a[y][b[y][2]];
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int q;
	
	scanf("%d",&q);
	
	while(q--){
		int n;
		scanf("%d",&n);
		for(int j=0;j<=3;j++) vec[j].clear();
		int res=0;
		for(int i=1;i<=n;i++){
			a[i][0]=-1;
			int fs=0,sc=0;
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]>a[i][fs]){
					sc=fs;
					fs=j;
				}else if(a[i][j]>a[i][sc]) sc=j;
			}
			b[i][1]=fs;
			b[i][2]=sc;
			b[i][3]=6-fs-sc;
			vec[fs].push_back(i);
			res+=a[i][b[i][1]];
		}
		int t1=0,t2=0;
		for(int j=1;j<=3;j++){
			if(vec[j].size()>vec[t1].size()){
				t2=t1;
				t1=j;
			}else if(vec[j].size()>vec[t2].size()) t2=j;
		}
		int t3=6-t1-t2;
		if((int)vec[t1].size()<n/2){
			printf("%d\n",res);
			continue;
		}else{
			if(vec[t3].empty()&&(n&1)){
				int tx=1;
				for(int i=2;i<=n;i++){
					if(a[i][b[i][1]]-a[i][t3]<a[tx][b[tx][1]]-a[tx][t3]) tx=i;
				}
				res-=(a[tx][b[tx][1]]-a[tx][t3]);
				for(int j=0;j<(int)vec[b[tx][1]].size();j++){
					if(vec[b[tx][1]][j]==tx){
						for(int k=j+1;k<(int)vec[b[tx][1]].size();k++) vec[b[tx][1]][k-1]=vec[b[tx][1]][k];
						vec[b[tx][1]].pop_back();
						break;
					}
				}
			}
			sort(vec[t1].begin(),vec[t1].end(),cmp);
			for(int j=n/2;j<(int)vec[t1].size();j++){
				int tmp=vec[t1][j];
				res-=(a[tmp][t1]-a[tmp][b[tmp][2]]);
			}
			printf("%d\n",res);
		}
	}
	
	return 0;
}