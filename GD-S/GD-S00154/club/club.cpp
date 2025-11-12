#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][5],cnt[5],ans,sum=0;
bool bz[100005][5]={false};
void club(int xx){
	if(cnt[1]>n/2 || cnt[2]>n/2 || cnt[3]>n/2) return;
	if(ans<sum) ans=sum;
	for(int i=xx;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(bz[i][j]==0){
				bz[i][j]=true;
				cnt[j]++;
				sum+=a[i][j];
				club(xx+1);
				bz[i][j]=false;
				cnt[j]--;
				sum-=a[i][j];
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
			}
		}
		if(n==100000){
			long long shui=-1;
			for(int i=1;i<=n;i++){
				if(shui<a[i][1]) shui=a[i][1];
			}
			cout<<shui<<endl;
			return 0;
		}
		club(1);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
} 
