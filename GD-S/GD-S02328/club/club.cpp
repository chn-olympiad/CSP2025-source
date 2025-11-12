#include<iostream>
#include<algorithm>
using namespace std;
int t,n,a[100005][5];
int cnta,cntb,cntc,sum,maxx;
void dfs(int i,int j){
	if(i>=n){
		maxx=max(maxx,sum);
		return ;
	}
	if((cnta+1)<=(n/2)){
		sum+=a[i+1][1];
		cnta++;
		dfs(i+1,1);
		cnta--;
		sum-=a[i+1][1];
	}
	if((cntb+1)<=(n/2)){
		sum+=a[i+1][2];
		cntb++;
		dfs(i+1,2);
		cntb--;
		sum-=a[i+1][2];
	}if((cntc+1)<=(n/2)){
		sum+=a[i+1][3];
		cntc++;
		dfs(i+1,3);
		cntc--;
		sum-=a[i+1][3];
	}
}
bool f=0;
int o[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		cnta=0;cntb=0,cntc=0,sum=0,maxx=0;
		for(int i=1;i<=100004;i++){
			a[i][1]=0;
			a[i][2]=0;
			a[i][3]=0;
		}
		for(int i=1;i<=100004;i++){
			o[i]=0;
		}
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];	
			if((a[i][2]!=0||a[i][3]!=0)&&!f){
				f=1;
			}
			if(!f){
				o[i]=a[i][1];
			}
		}
		if(f){
			dfs(0,1);
			cout<<maxx<<endl;
		}else{
			sort(o+1,o+n+1);
			int ans=0;
			for(int i=n;i>n/2;i--){
				ans+=o[i];
			}
			cout<<ans<<endl;
		}
	}
} 
