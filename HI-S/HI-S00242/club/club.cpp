#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
struct node{
	int id,h;
}a1[200005],a2[200005],a3[200005];
bool was[200005];
bool cmp(node a,node b){
	return a.h>b.h;
}
void dfs(int now,int t1,int t2,int t3,int sum){
	if(now==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(t1<n/2){
		dfs(now+1,t1+1,t2,t3,sum+a1[now].h);
	}
	if(t2<n/2){
		dfs(now+1,t1,t2+1,t3,sum+a2[now].h);
	}
	if(t3<n/2){
		dfs(now+1,t1,t2,t3+1,sum+a3[now].h);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(was,0,sizeof(was));
		ans=0;
		bool pd2=0,pd3=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a1[i].h>>a2[i].h>>a3[i].h;
			a1[i].id=i;
			a2[i].id=i;
			a3[i].id=i;
			if(a2[i].h!=0){
				pd2=1;
			}
			if(a3[i].h!=0){
				pd3=1;
			}
		}
		
		sort(a1+1,a1+n+1,cmp);
		sort(a2+1,a2+n+1,cmp);
		sort(a3+1,a3+n+1,cmp);
		/*
		int tot1=0,tot2=0,tot3=0;
		for(int i=1,s1=1,s2=1,s3=1;i<=n;++i){
			while(was[a1[s1].id]==1){
				s1++;
			}
			while(was[a2[s2].id]==1){
				s2++;
			}
			while(was[a3[s3].id]==1){
				s3++;
			}
			node now[4];now[1]=a1[s1];now[2]=a2[s2];now[3]=a3[s3];
			sort(now+1,now+4,cmp);
			node st=now[1],nd=now[2],rd=now[3];
			if()
			ans+=now[1].h;
			was[now[1].id]=1;
		}*/
		if(pd3==0){
			if(pd2==0){
				for(int i=1;i<=n/2;++i){
					ans+=a1[i];
				}
			}
			else{
				
			}
		}
		else{
			dfs(1,0,0,0,0);	
		}
		cout<<ans<<"\n";
	}
	return 0;
}
