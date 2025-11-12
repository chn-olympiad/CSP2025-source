#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[100005][4],maxn,d[4];
void dfs(int cs,int cnt){
//	cout<<cnt<<endl;
	if(cs==n){
		maxn=max(maxn,cnt);
	    return ;
	}
	for(int i=1;i<=3;i++){
		if(d[i]+1<=n/2){
			d[i]++;
			dfs(cs+1,cnt+a[cs+1][i]);
			d[i]--;
		}
	}
}
//尝试贪心每次选最大的 若不合法 转次大... 
void dfs2(int cs,int cnt){
//	cout<<cnt<<endl;
	if(cs==n){
		maxn=max(maxn,cnt);
	    return ;
	}
	int p=a[cs+1][1],q=a[cs+1][2],k=a[cs+1][3];
	int maxans=max(p,max(q,k));
	if(maxans==p){
		if(d[1]+1<=n/2){
			d[1]++;
			dfs2(cs+1,cnt+p);
            d[1]--;
		}else{
			if(q>k){
				if(d[2]+1<=n/2){
					d[2]++;
				    dfs2(cs+1,cnt+q);
				    d[2]--;
				}else{
					d[3]++;
				    dfs2(cs+1,cnt+k);
				    d[3]--;
				}
			}else{
				if(d[3]+1<=n/2){
					d[3]++;
				    dfs2(cs+1,cnt+k);
				    d[3]--;
				}else{
					d[2]++;
				    dfs2(cs+1,cnt+q);
				    d[2]--;
				}
			}
		}
	}
	if(maxans==q){
		if(d[2]+1<=n/2){
			d[2]++;
			dfs2(cs+1,cnt+q);
            d[2]--;
		}else{
			if(p>k){
				if(d[1]+1<=n/2){
					d[1]++;
				    dfs2(cs+1,cnt+p);
				    d[1]--;
				}else{
					d[3]++;
				    dfs2(cs+1,cnt+k);
				    d[3]--;
				}
			}else{
				if(d[3]+1<=n/2){
					d[3]++;
				    dfs2(cs+1,cnt+k);
				    d[3]--;
				}else{
					d[1]++;
				    dfs2(cs+1,cnt+p);
				    d[1]--;
				}
			}
		}
	}
	if(maxans==k){
		if(d[3]+1<=n/2){
			d[3]++;
			dfs2(cs+1,cnt+k);
            d[3]--;
		}else{
			if(q>p){
				if(d[2]+1<=n/2){
					d[2]++;
				    dfs2(cs+1,cnt+q);
				    d[2]--;
				}else{
					d[1]++;
				    dfs2(cs+1,cnt+p);
				    d[1]--;
				}
			}else{
				if(d[1]+1<=n/2){
					d[1]++;
				    dfs2(cs+1,cnt+p);
				    d[1]--;
				}else{
					d[2]++;
				    dfs2(cs+1,cnt+q);
				    d[2]--;
				}
			}
		}
	}
}
signed main(){
	freopen("club.in ","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		maxn=-1;
		memset(d,0,sizeof(d));
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(n<=10)dfs(0,0);//............20pts
		if(n>10){
			dfs2(0,0);
		} 
		cout<<maxn<<endl;
	}
	return 0;
} 
