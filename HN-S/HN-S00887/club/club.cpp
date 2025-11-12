#include<bits/stdc++.h>
using namespace std;
int T,dp[100005][3];  
struct node{
	int sat[5],maxx,midd,minn,maxv;
}em[100005];
vector<int>s1;
vector<int>s2;
vector<int>s3;
bool check(){
	for(int i=1;i<=n;i++){
		if(!(em[i].sat[2]==0&&em[i].sat[3]==0))return 0;
	}
	return 1;
}
bool ck1(){
	for(int i=1;i<=n;i++){
		if(!em[i].sat[3]==0)return 0;
	}
	return 1;
}
bool cmp(node a,node b){
	return a.sat[1]>b.sat[1];
}
bool cmp1(node a,node b){
	return a.sat[1]+a.sat[2]+a.sat[3]>b.sat[1]+b.sat[2]+b.sat[3];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		memset(dp,0,sizeof(dp));
		s1.clear();s2.clear();s3.clear();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>em[i].sat[j];
			}
			em[i].maxv=*max_element(em[i].sat+1,em[i].sat+1+3);
			em[i].maxx=max_element(em[i].sat+1,em[i].sat+1+3)-em[i].sat;
			em[i].minn=min_element(em[i].sat+1,em[i].sat+1+3)-em[i].sat;
			for(int j=1;j<=3;j++){
				if(em[i].sat[j]!=em[i].maxx&&em[i].sat[j]!=em[i].minn){
					em[i].midd=j;
					break;
				}
			}
		}
		if(n==2){
			cout<<max({em[1].sat[1]+em[2].sat[2],em[1].sat[1]+em[2].sat[3],em[1].sat[2]+em[2].sat[3]})<<'\n';
			continue;
		}else if(check()){
			sort(em+1,em+1+n,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=em[i].sat[1];
			}
			cout<<sum<<'\n';
			continue;
		}else if(ck1()){
			sort(em+1,em+1+n,cmp);
			int sum=0;
			for(int i=1;i<=n;i++){
				if(s1.size()<n/2){
					if(em[i].sat[1]<em[i].sat[2]){
						if(s2.size()<n/2){
							s2.push_back(1);
							sum+=em[i].sat[2];
						}else{
							s1.push_back(1);
							sum+=em[i].sat[1];
						}
					}else{
						s1.push_back(1);
						sum+=em[i].sat[1];
					}
				}else{
					if(em[i].sat[1]>em[i].sat[2]){
						if(s1.size()<n/2){
							s1.push_back(1);
							sum+=em[i].sat[1];
						}else{
							s2.push_back(1);
							sum+=em[i].sat[2];
						}
					}else{
						s2.push_back(1);
						sum+=em[i].sat[2];
					}
				}
			}
		}else{
			sort(em,em+1+n,cmp1);
			int sum=0;
			for(int i=1;i<=n;i++){
				sum+=max({em[i].sat[1],em[i].sat[2],em[i].sat[3]});
			}
			cout<<sum<<'\n';
			continue;
		}
//		dp[1][1]=em[1].sat[1],dp[1][2]=em[1].sat[2],dp[1][3]=em[1].sat[3];
//		for(int i=2;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				if(s1.size()<n/2){
//					
//				}else if()
//			}
//		}
		
	}
	return 0;
}
