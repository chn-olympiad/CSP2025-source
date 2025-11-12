#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int a[N][3];
int tag[N];
int cnt[3];
int ans=0;
void work(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		for(int j=0;j<3;j++)
			if(a[i][j]>=max(a[i][(j+1)%3],a[i][(j+2)%3])){
				tag[i]=j,cnt[j]++,ans+=a[i][j];
				break;
			}
	}
	if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2)
		return cout<<ans<<"\n",void();
	//
	for(int j=0;j<3;j++){
		if(cnt[j]>n/2){
			vector<int>v;
			for(int i=1;i<=n;i++)
				if(tag[i]==j)
					v.push_back(a[i][j]-max(a[i][(j+1)%3],a[i][(j+2)%3]));
			sort(v.begin(),v.end());
			for(int i=0;i<cnt[j]-n/2;i++)ans-=v[i];
			cout<<ans<<"\n";
			return;
		}
	}
}
void clear(){
	ans=cnt[0]=cnt[1]=cnt[2]=0;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;cin>>_;
	while(_--)work(),clear();
	return 0;
} 
