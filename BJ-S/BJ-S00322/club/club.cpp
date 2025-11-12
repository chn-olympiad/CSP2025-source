#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,k;
long long ans;
int a[N][5];
int id[N];
int g[N];
struct node{
	int aa,bb;
}gg[N];
void dfs(int step,int cnt1,int cnt2,int cnt3){
	if(step==n+1){
		long long sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i][id[i]];
		}
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(i==1&&cnt1==k) continue;
		else if(i==2&&cnt2==k) continue;
		else if(i==3&&cnt3==k) continue;
		id[step]=i;
		if(i==1) cnt1++;
		else if(i==2) cnt2++;
		else if(i==3) cnt3++;
		dfs(step+1,cnt1,cnt2,cnt3);
		if(i==1) cnt1--;
		else if(i==2) cnt2--;
		else if(i==3) cnt3--;
	}
	return ;
}
bool cmp(int aaa,int bbb){
	return aaa>bbb;
}
bool cmp2(node aaa,node bbb){
	return aaa.aa>bbb.aa;
}
bool cmp3(node aaa,node bbb){
	return aaa.bb>bbb.bb;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>T;
	while(T--){
		bool flagA=true,flagB=true;
		cin>>n;
		ans=0;
		k=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][3]!=0) flagB=false;
			if(a[i][2]!=0||a[i][3]!=0) flagA=false;
		}
		if(n<=12){
			dfs(1,0,0,0);
		}
		else if(flagA==true){
			for(int i=1;i<=n;i++){
				g[i]=a[i][1];
			}
			sort(g+1,g+n+1,cmp);
			for(int i=1;i<=k;i++){
				ans+=g[i];
			}
		}
		else if(flagB==true){
			long long sum1=0,sum2=0;
			for(int i=1;i<=n;i++){
				gg[i].aa=a[i][1];
				gg[i].bb=a[i][2];
			}
			sort(gg+1,gg+n+1,cmp2);
			for(int i=1;i<=n;i++){
				if(i<=k) sum1+=gg[i].aa;
				else sum1+=gg[i].bb;
			}
			sort(gg+1,gg+n+1,cmp3);
			for(int i=1;i<=n;i++){
				if(i<=k) sum2+=gg[i].bb;
				else sum2+=gg[i].aa;
			}
			ans=max(sum1,sum2);
			//cout<<sum1<<" "<<sum2<<" ";
		}
		else{
			for(int i=1;i<=n;i++){
				ans+=max(a[i][1],max(a[i][2],a[i][3]));
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
