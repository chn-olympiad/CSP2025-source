#include<bits/stdc++.h>
using namespace std;
int op;
const int N=100100;
int n;
int a[N],b[N],c[N],sa,sb,sc,tmp;
bool vis[1001][4];
int maxx=-2121,ren;
void dfs(int now,int ans){
	if(now>n) return ;
	for(int i=1;i<=3;i++){
		if(i==1){
			if(sa>=ren) continue;
		}
		if(i==2){
			if(sb>=ren) continue;
		}
		if(i==3){
			if(sc>=ren) continue;
		}
		if(vis[now][i]==0&&now<=n){
			//cout<<now<<" "<<i<<endl;
			if(i==1){
				ans+=a[now];
				sa++;
				tmp=a[now];
			}if(i==2){
				ans+=b[now];
				sb++;
				tmp=b[now];
			}if(i==3){
				ans+=c[now];
				sc++;
				tmp=c[now];
			}
			if(now==n){
				maxx=max(maxx,ans);
				//cout<<maxx<<"%%"<<endl;
				ans-=tmp;
				if(i==1){
					sa--;
				}if(i==2){
					sb--;
				}if(i==3){
					sc--;
				}
				continue;
			}
			//cout<<sa<<" "<<sb<<" "<<sc<<"%%%$$$"<<endl;
			vis[now][i]=1;
			dfs(now+1,ans);
			vis[now][i]=0;
			if(i==1){
				ans-=a[now];
				sa--;
			}if(i==2){
				ans-=b[now];
				sb--;
			}if(i==3){
				ans-=c[now];
				sc--;
			}
		}
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>op;
	while(op--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		ren=n/2;
		dfs(1,0);
		cout<<maxx<<endl;
		maxx=-1231212;
	}
	return 0;
} 


//15:43 爆搜 20pts 