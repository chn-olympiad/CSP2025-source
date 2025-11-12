#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
const int N=100010;
int T,n,maxn,temp,now,sum,minn[N],a[N][5];
std::vector<int>v[5];
bool cmp(int x,int y){
	return minn[x]<minn[y];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin>>T;
	while(T--){
		std::cin>>n;
		maxn=(n>>1),sum=0;
		v[1].clear(),v[2].clear(),v[3].clear();
		for(int i=1;i<=n;i++){
			temp=-1,now=0;
			for(int j=1;j<=3;j++){
				std::cin>>a[i][j];
				if(a[i][j]>temp){
					temp=a[i][j],now=j;
				}
			}
			v[now].push_back(i);
			sum+=temp;
		}
		if(v[1].size()>maxn){
			now=1;
		}
		else if(v[2].size()>maxn){
			now=2;
		}
		else if(v[3].size()>maxn){
			now=3;
		}
		else{
			std::cout<<sum<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			minn[i]=N;
			for(int j=1;j<=3;j++){
				if(j==now){
					continue;
				}
				minn[i]=std::min(minn[i],std::abs(a[i][j]-a[i][now]));
			}
		}
		std::sort(v[now].begin(),v[now].end(),cmp);
		for(int i=0;v[now].size()-i>maxn;i++){
			sum-=minn[v[now][i]];
		}
		std::cout<<sum<<"\n";
	}
	return 0;
}
/*
O(Tnlogn)
t=5 n=1e5 5*1e5*log(1e5) 8e6 309ms
100
*/
