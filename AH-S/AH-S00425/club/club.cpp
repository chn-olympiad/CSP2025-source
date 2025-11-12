#include<bits/stdc++.h>
using namespace std;
struct p{
	int like[4];
}a[114514];
int t,n,expect[114514]={0};
int c1,c2,c3,ans=0;
void dfs(int x,int sum,int cnt1,int cnt2,int cnt3){
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	if(cnt1<(n/2)){
		dfs(x+1,sum+a[x].like[1],cnt1+1,cnt2,cnt3);
	}
	if(cnt2<(n/2)){
		dfs(x+1,sum+a[x].like[2],cnt1,cnt2+1,cnt3);
	}
	if(cnt3<(n/2)){
		dfs(x+1,sum+a[x].like[3],cnt1,cnt2,cnt3+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		c1=0;
		c2=0;
		c3=0;
		for(int i=1;i<=n;i++){
			int maxx=0;
			for(int j=1;j<=3;j++){
				cin>>a[i].like[j];
				if(a[i].like[j]>maxx){
					maxx=a[i].like[j];
					expect[i]=j;//记录期望
				}
			}
			if(expect[i]==1)c1++;
			if(expect[i]==2)c2++;
			if(expect[i]==3)c3++;
		}
		if(c1>(n/2)||c2>(n/2)||c3>(n/2)){//如果会多人
			dfs(1,0,0,0,0);
		}
		else{//如果不会
			for(int i=1;i<=n;i++){
				ans+=a[i].like[expect[i]];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
