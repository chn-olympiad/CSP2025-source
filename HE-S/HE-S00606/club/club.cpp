#include<bits/stdc++.h>
using namespace std;

int n,t;
int m; 
struct Node{
	int f1,f2,f3;
};
Node in[100010];

int sum;
int ans;

void dfs2(int now); 
void dfs2_(int now); 
int cnt1,cnt2,cnt3;
bool vis1[210];
bool vis2[210];
bool vis3[210];

bool vis[100010];
void dfs(int m);
int cnt;

bool cmppf(Node xc,Node yc){
	return xc.f1>yc.f1;
}

bool pf=0;
bool pff1,pff2;
int main(){
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(false);
	
	cin>>t;
	while(t--){
		cin>>n;
		m=n/2;
		
		for(int i=1;i<=n;i++){
			cin>>in[i].f1>>in[i].f2>>in[i].f3;
			if(in[i].f2!=0 || in[i].f3!=0)pf=1;
			if(in[i].f2!=0)pff1=1;
			if(in[i].f3!=0)pff2=1;
		}
		
		if(!pf){
			sort(in+1,in+1+n,cmppf);
			for(int i=1;i<=m;i++){
				ans+=in[i].f1;
			}
			cout<<ans<<'\n';
			ans=0;
			continue;
		}
		
		if(pff1==1 && pff2==0){
			dfs(1);
			cout<<ans<<'\n';
			ans=0;
			continue;
		}
		
		dfs2(1);
		cout<<ans<<'\n';
		
		ans=0;sum=0;
		fill(vis1+1,vis1+205,0);
		fill(vis2+1,vis2+205,0);
		fill(vis3+1,vis3+205,0);
		fill(vis+1,vis+100009,0);
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}


void dfs2(int now){
	for(int i=1;i<=n;i++){
		if(!vis1[i]){
			vis1[i]=1;
			sum+=in[i].f1;
			cnt1++;
			if(now<=m){
				dfs2_(1);
				
			}
			if(now<m)dfs2(now+1);
			vis1[i]=0;
			sum-=in[i].f1;
			cnt1--;
		}
	}
}
void dfs2_(int now){
	for(int i=1;i<=n;i++){
		if(!vis2[i]  && !vis1[i]){
			vis2[i]=1;
			sum+=in[i].f2;
			cnt2++;
			if(now<=m){
				cnt3=n-(cnt1+cnt2);
				if(cnt3<=m){
					int sum1=sum;
					for(int j=1;j<=n;j++){
						if(!vis1[j] && !vis2[j]){
							
							vis3[j]=1;
							
							sum1+=in[j].f3;
						} 
					}
					
					ans=max(ans,sum1);
				}
			}
			if(now<m)dfs2_(now+1);
			sum-=in[i].f2;
			cnt2--;
			vis2[i]=0;
		}
	}
	return ;
}



void dfs(int now){
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			sum+=in[i].f1;
			if(now==m){
				
//				for(int i=1;i<=n;i++){
//					cout<<vis[i]<<' ';
//				}
				
				int sum1=sum;
				for(int j=1;j<=n;j++){
					if(!vis[j])sum1+=in[j].f2;
				}
				ans=max(sum1,ans);
				
//				cout<<sum1<<'\n';
			}
			else{
				dfs(now+1);
			}
			vis[i]=0;
			sum-=in[i].f1;
		}
	}
	return ;
}
