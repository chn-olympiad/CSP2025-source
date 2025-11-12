#include<bits/stdc++.h>
using namespace std;
int hgd[100010][4];
int zt[100010];
int num[4];
vector<pair<int,int>>dj;
int main(){
	freopen("r","club.in",stdin);
	freopen("w","club.out",stdout);
	int t;cin>>t;
	for(int p=1;p<=t;p++){
		num[1]=num[2]=num[3]=0;
		long long ans=0;
		int n;cin>>n;
		for(int i=1;i<=n;i++)cin>>hgd[i][1]>>hgd[i][2]>>hgd[i][3];
		for(int i=1;i<=n;i++){
			if((hgd[i][1]>=hgd[i][2])&&(hgd[i][1]>=hgd[i][3]))zt[i]=1,num[1]++;
			else if(hgd[i][2]>=hgd[i][3])zt[i]=2,num[2]++;
			else zt[i]=3,num[3]++;
			ans+=hgd[i][zt[i]];
		}
		int xy=0;
		if(num[1]>n/2){
			xy=num[1]-n/2;
			for(int i=1;i<=n;i++)
				if(zt[i]==1){
					if(hgd[i][2]>hgd[i][3])dj.push_back({hgd[i][1]-hgd[i][2],2});
					else				   dj.push_back({hgd[i][1]-hgd[i][3],3});
				}
		}
		if(num[2]>n/2){
			xy=num[2]-n/2;
			for(int i=1;i<=n;i++)
				if(zt[i]==2){
					if(hgd[i][1]>hgd[i][3])dj.push_back({hgd[i][2]-hgd[i][1],1});
					else				   dj.push_back({hgd[i][2]-hgd[i][3],3});
				}
		}
		if(num[3]>n/2){
			xy=num[3]-n/2;
			for(int i=1;i<=n;i++)
				if(zt[i]==3){
					if(hgd[i][1]>hgd[i][2])dj.push_back({hgd[i][3]-hgd[i][1],1});
					else				   dj.push_back({hgd[i][3]-hgd[i][2],2});
				}
		}
		sort(dj.begin(),dj.end());
		for(int i=0;i+1<=xy;i++)zt[i]=dj[i].second,ans-=dj[i].first;
		cout<<ans<<endl;
		dj.clear();
	}
	return 0;
}
