#include<bits/stdc++.h>
#define int long long
using namespace std;
int maxx(int a,int b,int c){
	return max(a,max(b,c));
}
int midx(int a,int b,int c){
	return max(a,min(b,c));
}
int minx(int a,int b,int c){
	return min(a,min(b,c));
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		int ans=0,ans1=0;
		int cnt[3]={0,0,0};
		bool vis[n+5];
		memset(vis,false,sizeof(vis));
		int d1[n+5],d2[n+5],d3[n+5];
		for(int i=1;i<=n;i++){
			cin>>d1[i]>>d2[i]>>d3[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(d1[i]>d1[j]){
					swap(d1[i],d1[j]);
					swap(d2[i],d2[j]);
					swap(d3[i],d3[j]);
				}else if(d1[i]==d1[j]){
					if(d2[i]>d2[j]){
						swap(d1[i],d1[j]);
						swap(d2[i],d2[j]);
						swap(d3[i],d3[j]);
					}else if(d2[i]==d2[j]){
						if(d3[i]>d3[j]){
							swap(d1[i],d1[j]);
							swap(d2[i],d2[j]);
							swap(d3[i],d3[j]);
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(maxx(d1[i],d2[i],d3[i])==d1[i]){
				if(cnt[0]<n/2){
					cnt[0]++;
					ans+=d1[i];
				}else{
					if(midx(d1[i],d2[i],d3[i])==d2[i]){
						cnt[1]++;
						ans+=d2[i];
					}else{
						cnt[2]++;
						ans+=d3[i];
					}
				}
			}else if(maxx(d1[i],d2[i],d3[i])==d2[i]){
				if(cnt[1]<n/2){
					cnt[1]++;
					ans+=d2[i];
				}else{
					if(midx(d1[i],d2[i],d3[i])==d1[i]){
						cnt[0]++;
						ans+=d1[i];
					}else{
						cnt[2]++;
						ans+=d3[i];
					}
				}
			}else{
				if(cnt[2]<n/2){
					cnt[2]++;
					ans+=d3[i];
				}else{
					if(midx(d1[i],d2[i],d3[i])==d2[i]){
						cnt[1]++;
						ans+=d2[i];
					}else{
						cnt[0]++;
						ans+=d1[i];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(d1[i]<d1[j]){
					swap(d1[i],d1[j]);
					swap(d2[i],d2[j]);
					swap(d3[i],d3[j]);
				}else if(d1[i]==d1[j]){
					if(d2[i]<d2[j]){
						swap(d1[i],d1[j]);
						swap(d2[i],d2[j]);
						swap(d3[i],d3[j]);
					}else if(d2[i]==d2[j]){
						if(d3[i]<d3[j]){
							swap(d1[i],d1[j]);
							swap(d2[i],d2[j]);
							swap(d3[i],d3[j]);
						}
					}
				}
			}
		}
		ans1=ans;
		ans=0;
		cnt[0]=0;cnt[1]=0;cnt[2]=0;
		for(int i=1;i<=n;i++){
			if(maxx(d1[i],d2[i],d3[i])==d1[i]){
				if(cnt[0]<n/2){
					cnt[0]++;
					ans+=d1[i];
				}else{
					if(midx(d1[i],d2[i],d3[i])==d2[i]){
						cnt[1]++;
						ans+=d2[i];
					}else{
						cnt[2]++;
						ans+=d3[i];
					}
				}
			}else if(maxx(d1[i],d2[i],d3[i])==d2[i]){
				if(cnt[1]<n/2){
					cnt[1]++;
					ans+=d2[i];
				}else{
					if(midx(d1[i],d2[i],d3[i])==d1[i]){
						cnt[0]++;
						ans+=d1[i];
					}else{
						cnt[2]++;
						ans+=d3[i];
					}
				}
			}else if(maxx(d1[i],d2[i],d3[i])==d3[i]){
				if(cnt[2]<n/2){
					cnt[2]++;
					ans+=d3[i];
				}else{
					if(midx(d1[i],d2[i],d3[i])==d2[i]){
						cnt[1]++;
						ans+=d2[i];
					}else{
						cnt[0]++;
						ans+=d1[i];
					}
				}
			}
		}
		cout<<max(ans,ans1)<<endl;
	}	
	return 0;
}
/*
车窗外 这夜色
流光溢彩 

别忘了 闭上眼
才算醒来

你参演 这场戏
变换姿态

谜底 结局
我该 怎么猜 
*/ 
