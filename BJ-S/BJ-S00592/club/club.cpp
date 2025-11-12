#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][10];
int ans,cnt[5][50005];
void init(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
			a[i][4]=1;
			if(a[i][2]>a[i][3]){
				a[i][5]=2;
				a[i][6]=3;
			}else{
				a[i][5]=3;
				a[i][6]=2;
			}
		}else if(a[i][2]>a[i][3]&&a[i][2]>a[i][1]){
			a[i][4]=2;
			if(a[i][3]>a[i][1]){
				a[i][5]=3;
				a[i][6]=1;
			}else{
				a[i][5]=1;
				a[i][6]=3;
			}
		}else{
			a[i][4]=3;
			if(a[i][1]>a[i][2]){
				a[i][5]=1;
				a[i][6]=2;
			}else{
				a[i][5]=2;
				a[i][6]=1;
			}
		}
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		init();
		for(int i=1;i<=n;i++){
			if(cnt[a[i][4]][0]<n/2){
				cnt[a[i][4]][++cnt[a[i][4]][0]]=i;
				ans+=a[i][a[i][4]];
			}else if(cnt[a[i][5]][0]<n/2){
				cnt[a[i][5]][++cnt[a[i][5]][0]]=i;
				ans+=a[i][a[i][5]];
			}else{
				cnt[a[i][6]][++cnt[a[i][6]][0]]=i;
				ans+=a[i][a[i][5]];
			}
		}
		cout<<ans<<endl;
		n=ans=0;
		memset(a,0,sizeof(a));
		memset(cnt,0,sizeof(cnt));
	}
	return 0;
}