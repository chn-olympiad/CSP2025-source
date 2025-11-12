#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+7;
int T;
int n;
LL a[N][5],ans=0;
int o[N],cnt[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cnt[1]=0,cnt[2]=0,cnt[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][1]){
				o[i]=1;
				cnt[1]++;
			}else if(max(a[i][2],max(a[i][1],a[i][3]))==a[i][2]){
				o[i]=2;
				cnt[2]++;
			}else o[i]=3,cnt[3]++;
			sort(a[i]+1,a[i]+1+3); 
			reverse(a[i]+1,a[i]+1+3);
			ans+=a[i][1];
		}
		int k;
		if(cnt[1]>n/2) k=1;
		else if(cnt[2]>n/2) k=2;
		else if(cnt[3]>n/2) k=3;
		else {
			cout<<ans<<endl;
			continue;
		}
		int tmp[N]={0},tot=0;
		for(int i=1;i<=n;i++){
			if(o[i]==k){
				tmp[++tot]=a[i][1]-a[i][2];
			}
		}
		sort(tmp+1,tmp+1+tot);
	//	for(int i=1;i<=tot;i++) cout<<tmp[i]<<" ";
	//	cout<<endl;
		for(int i=1;i<=cnt[k]-n/2;i++) ans-=tmp[i];
		cout<<ans<<endl;
	} 
	return 0;
}
