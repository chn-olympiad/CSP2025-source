#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;
int n;
int a[N][4];
int num[4];
int fst[N],snd[N],trd[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(fst,0,sizeof(fst));
		memset(snd,0,sizeof(snd));
		memset(trd,0,sizeof(trd));
		memset(num,0,sizeof(num));
		int pos=0,cnt=0,tot=0;
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
				ans+=a[i][1];
				num[1]++;
				fst[++pos]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
			}
			else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
				ans+=a[i][2];
				num[2]++;
				snd[++cnt]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
			}
			else if(a[i][3]>=a[i][1] && a[i][3]>=a[i][2]){
				ans+=a[i][3];
				num[3]++;
				trd[++tot]=min(a[i][3]-a[i][2],a[i][3]-a[i][1]);
			}
		}
		int k=0;
		if(num[1]>n/2) k=1;
		else if(num[2]>n/2) k=2;
		else if(num[3]>n/2) k=3;
		if(k==1){
			sort(fst+1,fst+pos+1);
			for(int i=1;i<=pos;i++){
				ans-=fst[i];
				num[1]--;
				if(num[1]<=n/2) break;
			}
		}
		else if(k==2){
			sort(snd+1,snd+cnt+1);
			for(int i=1;i<=cnt;i++){
				ans-=snd[i];
				num[2]--;
				if(num[2]<=n/2) break;
			}
		}
		else if(k==3){
			sort(trd+1,trd+tot+1);
			for(int i=1;i<=tot;i++){
				ans-=trd[i];
				num[3]--;
				if(num[3]<=n/2) break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 