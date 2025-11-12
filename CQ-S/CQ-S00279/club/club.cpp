#include<bits/stdc++.h>
using namespace std;
//4 hours!!!
//too long time!!!
const int N=1e5+5;
int t;
int a[N][5];
int k=0;
int n;
struct aaa{
	int sum1,cnt1;
	int sum2,cnt2;
	int sum3,cnt3;
};
int ans=0;
void dfs(aaa x,int u){
	if(x.cnt1>k||x.cnt2>k||x.cnt3>k){
		return ;
	}
	if(u==n){
//		cout<<x.sum1<<" "<<x.sum2<<" "<<x.sum3<<"\n";
		ans=max(ans,x.sum1+x.sum2+x.sum3);
		return ;
	}
	aaa y;
	y=x;
	y.cnt1++,y.sum1+=a[u+1][1];
	dfs(y,u+1);
	y.cnt1--,y.sum1-=a[u+1][1];
	
	y.cnt2++,y.sum2+=a[u+1][2];
	dfs(y,u+1);
	y.cnt2--,y.sum2-=a[u+1][2];
	
	y.cnt3++,y.sum3+=a[u+1][3];
	dfs(y,u+1);
	y.cnt3--,y.sum3-=a[u+1][3];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    cin>>t;
    while(t--){
    	ans=0;
    	cin>>n;
    	k=n/2;
    	int cnt2=0,cnt3=0;
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=3;j++){
    			cin>>a[i][j];
			}
			if(a[i][2]==0) cnt2++;
			if(a[i][3]==0) cnt3++;
		}
		if(cnt2==n&&cnt3==n){
			int ans=0;
			for(int i=1;i<=n;i++){
				ans+=a[i][1];
			}cout<<ans<<"\n";
		}else{
	    	aaa s={0,0,0,0,0,0};
	    	dfs(s,0);
	    	cout<<ans<<"\n";
		}
	}
    
    return 0;
}
/*
3
4 
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

