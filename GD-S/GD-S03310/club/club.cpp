#include<bits/stdc++.h>
using namespace std;
int n,a[100005][3],t,num[3],fso[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(fso,0,sizeof(fso));
		memset(num,0,sizeof(num));
		cin>>n;
		int ans=0,cnt=0;
		for(int i=1;i<=n;++i){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2])num[0]++;
			else if(a[i][1]>a[i][2]&&a[i][1]>a[i][0])num[1]++;
			else num[2]++;
		}
		if(num[0]<num[1]){
			swap(num[0],num[1]);
			for(int i=1;i<=n;++i)swap(a[i][0],a[i][1]);
		}
		if(num[0]<num[2]){
			swap(num[0],num[2]);
			for(int i=1;i<=n;++i)swap(a[i][0],a[i][2]);
		}
		for(int i=1;i<=n;++i){
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2])fso[++cnt]=a[i][0]-max(a[i][1],a[i][2]);
			ans+=max(a[i][0],max(a[i][1],a[i][2]));
		}
		if(num[0]<=n/2){
			cout<<ans<<endl;
			continue;
		}
		sort(fso+1,fso+num[0]+1);
		for(int i=1;i<=num[0]-n/2;++i){
			ans-=fso[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
