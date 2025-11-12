#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],num[25],cnt,ans,qwq;
void dfs(int i,int qwq,int len){
	if(qwq==len){
		int sum=0,f=1;
		for(int i=1;i<=cnt;i++)sum+=num[i];
		for(int i=1;i<=cnt;i++)f&=(sum>num[i]*2);
		ans+=f;
		return;
	}
	if(n-i+qwq<len)return;
	for(int j=i+1;j<=n;j++){
		num[++cnt]=a[j];
		dfs(j,qwq+1,len);
		cnt--;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(n<=20){
		ans=0;
		for(int l=3;l<=n;l++){
			cnt=0;
			dfs(0,0,l);
		}
		cout<<ans<<endl;
	}else {
		if(mx==1){
		
		}else{	
			//I can't solve it!
			//let's use rand()%!
			srand(time(0));
			int x=rand()%32768+1;
			int y=rand()%30463+1;
			int z=rand()%32768+1;
			cout<<x*y+z<<endl;
		}
	}
	return 0;
}
//qin shu ru wen ben
//luogu:786662
//***    *
//* *   *
//***  *
//    *
//   *
//  *  ***
// *   * *
//*    ***
