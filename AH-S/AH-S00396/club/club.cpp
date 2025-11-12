#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,cishu;
int cnta,cntb,cntc;
int flag;
int a[100005][4];
int t;
int vmax;
void dfs(long long step,long long num){
	if(step==n+1){
		ans=max(ans,num);
		return ;
	}
	if(cnta<cishu){
		cnta++;
		dfs(step+1,num+a[step][1]);
		cnta--;
	}
	if(cntb<cishu){
		cntb++;
		dfs(step+1,num+a[step][2]);
		cntb--;
	}if(cntc<cishu){
		cntc++;
		dfs(step+1,num+a[step][3]);
		cntc--;
	}
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
//  > (lol) <
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cnta=cntb=cntc=0;
		cin>>n;
		cishu=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
