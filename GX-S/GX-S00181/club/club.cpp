#include<bits/stdc++.h>
using namespace std;
long long int t,n,a[100005][5],cnt[5],bestans,ans;
short int situ[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int u=1;u<=t;u++){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			situ[i]=1;
		}
		for(;;){
			ans=cnt[1]=cnt[2]=cnt[3]=0;
			for(int i=1;i<=n;i++){
				ans+=a[i][situ[i]];
				cnt[situ[i]]++;
				if(cnt[situ[i]]>(n/2)){
					ans=0;break;
				}
			}
			bestans = max(bestans,ans);
			for(int i=n,flag=0;i>=1;i--){
				situ[i]++;flag=0;
				if(situ[1]==4)break;
				if(situ[i]==4){
					situ[i]=1;
					flag=1;
				}
				if(flag==0)break;
			}
			//cout << "#" << situ[1] << "\n";
			if(situ[1]==4)break;
		}
		cout << bestans << "\n";
		bestans=0;
	}
}
//20
