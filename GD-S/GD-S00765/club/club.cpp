#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N][5],b[N],cnt[5],ans,c[N],ccnt;
void init(){
	cnt[1]=cnt[2]=cnt[3]=0;
	ans=0;
	ccnt=0;
}
void solve(){
	cin>>n;
	init();
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])b[i]=1,cnt[1]++,ans+=a[i][1];
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])b[i]=2,cnt[2]++,ans+=a[i][2];
		else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])b[i]=3,cnt[3]++,ans+=a[i][3];
	}
	int p;
	if(cnt[1]>=cnt[2]&&cnt[1]>=cnt[3])p=1;
	else if(cnt[2]>=cnt[1]&&cnt[2]>=cnt[3])p=2;
	else p=3;
	for(int i=1;i<=n;i++){
		if(b[i]==p){
			if(p==1)c[++ccnt]=a[i][1]-max(a[i][2],a[i][3]); 
			if(p==2)c[++ccnt]=a[i][2]-max(a[i][1],a[i][3]); 
			if(p==3)c[++ccnt]=a[i][3]-max(a[i][1],a[i][2]); 
		}
	}
	sort(c+1,c+ccnt+1);
	int cc=0;
	while(cnt[p]>n/2)ans-=c[++cc],cnt[p]--;
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
