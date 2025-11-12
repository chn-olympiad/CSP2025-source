#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int t;
struct stu{
	int x,y;
};
int sum;
stu a[100005][5];
stu ans[5][100005];
int tt[100005];
bool cmp(stu xx,stu yy){
	return tt[xx.x]<tt[yy.x];
}
signed main(){
	freopen("club5.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int pos[5];pos[1]=1;pos[2]=1;pos[3]=1;
		memset(tt,0,sizeof(tt));
		memset(ans,0,sizeof(ans));
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j].x=i;
				cin>>a[i][j].y;
			}
		}
		
		for(int i=1;i<=n;i++){
			int maxn=0;
			int id=0;
			for(int j=1;j<=3;j++){
				if(a[i][j].y>=maxn){
					maxn=a[i][j].y;
					id=j;
				}
			}
			int mmm=0;
			int idd=0;
			for(int j=1;j<=3;j++){
				if(j==id)continue;
				if(a[i][j].y>=mmm){
					mmm=a[i][j].y;
					idd=j;
				}
			}
			//cout<<maxn<<" " <<mmm<<' '<<maxn-mmm<<endl;
			tt[i]=maxn-mmm;
			pos[id]++;
			sum+=maxn;
			ans[id][pos[id]-1]=a[i][id];
		}
		
		for(int i=1;i<=3;i++)pos[i]--;
		int ii=0;
		for(int i=1;i<=3;i++){
			if(pos[i]>(n/2)){
				ii=i;
			}
			
			 
		}
		if(ii==0){
			cout<<sum<<endl;
		    continue;
		}//cout<<ii<<"!";
		sort(ans[ii]+1,ans[ii]+pos[ii]+1,cmp);
		
		for(int i=1;i<=pos[ii]-(n/2);i++){
			//cout<<tt[ans[ii][i].x]<<" ! ";
			sum=sum-tt[ans[ii][i].x];
		}
		for(int i=1;i<=3;i++){
			for(int j=1;j<=pos[i];j++){
				//cout<<tt[ans[i][j].x]<<" ";
			}
			//cout<<endl;
		}
		cout<<sum<<endl;
	}
}
