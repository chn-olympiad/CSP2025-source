#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int t,n,a[100005][3],id[100005],s[100005],tot,cnt[3],rans[6],totrans;
void work(){
	cin>>n;
	int ans=0;
	for(int i=0;i<=2;i++) cnt[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=2;j++){
			cin>>a[i][j];
		}
		if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]) id[i]=0;
		else if(a[i][1]>a[i][2]) id[i]=1;
		else id[i]=2;
		ans+=a[i][id[i]];
		cnt[id[i]]++;
	}
	int hwh=-1;
	if(cnt[0]>n/2) hwh=0;
	else if(cnt[1]>n/2) hwh=1;
	else if(cnt[2]>n/2) hwh=2;
	if(hwh==-1){
		rans[++totrans]=ans;
		return;
	}
	tot=0;
	for(int i=1;i<=n;i++){
		if(id[i]==hwh){
			tot++;
			int x,y;
			if(hwh==0){
				x=1;
				y=2;
			}
			else if(hwh==1){
				x=0;
				y=2;
			}
			else{
				x=0;
				y=1;
			}
			if(a[i][x]>a[i][y]){
				s[tot]=a[i][hwh]-a[i][x];
			}
			else{
				s[tot]=a[i][hwh]-a[i][y];
			}
		}
	}
	sort(s+1,s+tot+1);
	for(int i=1;i<=cnt[hwh]-n/2;i++){
		ans-=s[i];
	}
	rans[++totrans]=ans;
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		work();
	}
	for(int i=1;i<=totrans;i++) cout<<rans[i]<<endl;
	return 0;
}
