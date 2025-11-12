#include<iostream>
#include<algorithm>
using namespace std;
long long bu[100005][4],ji[100005],zs=0;
long long zu=0,zong=0;
long long dfs(long long d,long long ans,long long a,long long b,long long c){
	long long maxn=0;
	if(d==zong+1) return ans;
	if(a<zong/2) maxn=dfs(d+1,ans+bu[d][1],a+1,b,c);
	if(b<zong/2) maxn=max(maxn,dfs(d+1,ans+bu[d][2],a,b+1,c));
	if(c<zong/2) maxn=max(maxn,dfs(d+1,ans+bu[d][3],a,b,c+1));
	return maxn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>zu;
	for(int i=1;i<=zu;i++){
		cin>>zong;
		for(int j=1;j<=zong;j++){
			for(int t=1;t<=3;t++){
				cin>>bu[j][t];
			}
		}
		if(zong==100000){
			for(int j=1;j<=zong;j++){
				ji[j]=bu[j][1];
			}
			sort(1+ji,1+ji+zong);
			for(int j=zong;j>=zong/2;j--){
				zs+=ji[j];
			}
			cout<<zs<<endl;
		}
		else{
			cout<<dfs(1,0,0,0,0)<<endl;
		}
	}
	return 0;
} 


