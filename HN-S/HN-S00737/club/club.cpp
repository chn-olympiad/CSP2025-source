#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define DB double
const int N=100005,inf=0x3f3f3f3f;
int n,onn,twn,thn,a[N][3],on[N],tw[N],th[N],ax[N];
bool fla,flb;
LL ans=0;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int t){
	if(t>n){
		LL sum=0;
		for(int i=1;i<=onn;i++){
			sum+=on[i];
		}
		for(int i=1;i<=twn;i++){
			sum+=tw[i];
		}
		for(int i=1;i<=thn;i++){
			sum+=th[i];
		}
		ans=max(ans,sum);
	}
	else{
      if(onn<n/2){
      	on[++onn]=a[t][1];
      	dfs(t+1);
      	onn--;
		}
		if(twn<n/2){
			tw[++twn]=a[t][2];
			dfs(t+1);
			twn--;
		}
		if((thn<n/2)and(!flb)){
			th[++thn]=a[t][3];
			dfs(t+1);
			thn--;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		fla=1,flb=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			ax[i]=a[i][1];
			if(a[i][2]!=0){
				fla=0;
			} 
			if(a[i][3]!=0){
				flb=0;
			}
		}
		onn=0,twn=0,thn=0,ans=0;
		if(fla&&flb){
			sort(ax+1,ax+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=ax[i];
			}
		}
		else{
			if(flb){
				int cha[n+5],num=0;
				for(int i=1;i<=n;i++){
               cha[i]=a[i][1]-a[i][2];
               num+=a[i][1];
				}
				sort(cha+1,cha+n+1);
				for(int i=1;i<=n/2;i++){
					num-=cha[i];
				}
				ans=num;
			}
			else{
				dfs(1);				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
