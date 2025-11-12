#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int n,A[100005][5];
int cnt[5];
int getmx(int i){
	if(A[i][1]>=A[i][2]&&A[i][1]>=A[i][3]) return 1;
	else if(A[i][2]>=A[i][1]&&A[i][2]>=A[i][3]) return 2;
	else return 3;
}
bool cmp1(int x,int y){return max(A[x][2],A[x][3])-A[x][1]>max(A[y][2],A[y][3])-A[y][1];}
bool cmp2(int x,int y){return max(A[x][1],A[x][3])-A[x][2]>max(A[y][1],A[y][3])-A[y][2];}
bool cmp3(int x,int y){return max(A[x][1],A[x][2])-A[x][3]>max(A[y][1],A[y][2])-A[y][3];}
void solve(){
	scanf("%d",&n);
	cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&A[i][1],&A[i][2],&A[i][3]);
	int ans=0;
	for(int i=1;i<=n;i++){
		cnt[getmx(i)]++;
		ans+=A[i][getmx(i)];
	}
	if(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2){
		vector<int> v[5];
		for(int i=1;i<=n;i++) v[getmx(i)].push_back(i);
		if(v[1].size()>n/2){
			sort(v[1].begin(),v[1].end(),cmp1);
			for(int i=0;i+n/2<v[1].size();i++)
				ans-=A[v[1][i]][1],ans+=max(A[v[1][i]][2],A[v[1][i]][3]);
		}
		else if(v[2].size()>n/2){
			sort(v[2].begin(),v[2].end(),cmp2);
			for(int i=0;i+n/2<v[2].size();i++)
				ans-=A[v[2][i]][2],ans+=max(A[v[2][i]][1],A[v[2][i]][3]);
		}else if(v[3].size()>n/2){
			sort(v[3].begin(),v[3].end(),cmp3);
			for(int i=0;i+n/2<v[3].size();i++)
				ans-=A[v[3][i]][3],ans+=max(A[v[3][i]][1],A[v[3][i]][2]);
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
} 
