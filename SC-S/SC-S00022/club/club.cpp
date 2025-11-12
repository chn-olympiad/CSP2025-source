#include<bits/stdc++.h>
using namespace std;
struct node{
	int s1,s2,s3,stz,stc,stzs,stcs;
};
node a[100500];
int num[4];
bool vis[100500];
bool cmp(node p1,node p2){
	if(p1.stzs==p2.stzs){
		return p1.stcs<p2.stcs;
	}else{
		return p1.stzs>p2.stzs;
	}
}
int mx=0;
int n;
void dfs(int ans,int t1,int t2,int t3){
	if(t1+t2+t3>n){
		mx=max(mx,ans);
		return ;
	}
	if(t1<n/2){
		dfs(ans+a[t1+t2+t3].s1,t1+1,t2,t3);
	}
	if(t2<n/2){
		dfs(ans+a[t1+t2+t3].s2,t1,t2+1,t3);
	}
	if(t3<n/2){
		dfs(ans+a[t1+t2+t3].s3,t1,t2,t3+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		num[1]=0;
		num[2]=0;
		num[3]=0;
		cin>>n;
		bool tt=true;
		for(int i=1;i<=n;i++){
			vis[i]=0;
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
			a[i].stz=max(max(a[i].s1,a[i].s2),a[i].s3);
			if(a[i].s2!=a[i].s3||a[i].s2!=0||a[i].s3!=0){
				tt=false;
			}
			if(a[i].stz==a[i].s1){
				a[i].stz=1;
				a[i].stc=(a[i].s2>a[i].s3?2:3);
				a[i].stzs=a[i].s1;
				a[i].stcs=(a[i].s2>a[i].s3?a[i].s2:a[i].s3);
			}else if(a[i].stz==a[i].s2){
				a[i].stz=2;
				a[i].stc=(a[i].s1>a[i].s3?1:3);
				a[i].stzs=a[i].s2;
				a[i].stcs=(a[i].s1>a[i].s3?a[i].s1:a[i].s3);
			}else{
				a[i].stz=3;
				a[i].stc=(a[i].s1>a[i].s2?1:2);
				a[i].stzs=a[i].s3;
				a[i].stcs=(a[i].s1>a[i].s2?a[i].s1:a[i].s2);
			}
		}
		sort(a+1,a+n+1,cmp);
		if(n==2){
			cout<<max(a[1].stcs+a[2].stzs,a[1].stzs+a[2].stcs)<<endl;
		}else if(tt){
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i].s1;
			} 
			cout<<ans<<endl;
		}else if(n<=10){
			mx=0;
			dfs(0,0,0,0);
			cout<<mx<<endl;
		}else{
			int ans=0;
			for(int i=1;i<=n;i++){
				if(num[a[i].stz]==n/2){
					int t=-1;
					for(int j=i-1;j>=1;j--){
						if(a[j].stz==a[i].stz){
							if((a[i].stzs-a[i].stcs>a[j].stzs-a[j].stcs)&&vis[j]){
								vis[j]=0;
								vis[i]=1;
								if(t!=-1){
									vis[t]=1;
								}
								t=j;
								ans=(ans-a[j].stzs+a[j].stcs+a[i].stzs-a[i].stcs);
							}
						}
					}
					if(t==-1){
						ans+=a[i].stcs;
					}
				}else{
					vis[i]=1;
					num[a[i].stz]++;
					ans+=a[i].stzs;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}