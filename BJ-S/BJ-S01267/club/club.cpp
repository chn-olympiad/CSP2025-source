#include<bits/stdc++.h>
using namespace std;
long long n,a[100005][4],n2,a1[100005][3],cntt,cntt1,a2[100050];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		cntt1=0;
		cin>>n;n2=n/2;
		cntt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int z=max(max(a[i][1],a[i][2]),a[i][3]);
			a1[i][0]=z;
			int z3=min(min(a[i][1],a[i][2]),a[i][3]);
			int z2=a[i][1]+a[i][2]+a[i][3]-z-z3;
			a1[i][1]=z-z2;
			if(a1[i][0]==a[i][1])a1[i][2]=1;
			else if(a1[i][0]==a[i][2])a1[i][2]=2;
			else a1[i][2]=3;
		}
		long long cnt=0;
		if(0)cnt=0;
		else{
			map<int,int>mp;	
			long long cnt1=0,cnt2=0,cnt3=0;
			for(int i=1;i<=n;i++){
				if(a1[i][2]==1)cnt1++;
				else if(a1[i][2]==2)cnt2++;
				else cnt3++;
			}
			cnt=0;
			for(int i=1;i<=n;i++){
				cnt+=a1[i][0];
			}	
			if(cnt3>n2){
				int p=cnt3-n2;
				for(int i=1;i<=n;i++){
					if(a1[i][2]==3){
						mp[a1[i][1]]++;
					}
				}
				for(int i=0;i<=200005;i++){
					if(!p)break;
					if(mp[i]!=0){
						int o=min(p,mp[i]);
						p-=o;
						cnt-=o*i;
					}
				}
			}
			if(cnt2>n2){
				int p=cnt2-n2;
				for(int i=1;i<=n;i++){
					if(a1[i][2]==3){
						mp[a1[i][1]]++;
					}
				}
				for(int i=0;i<=200005;i++){
					if(!p)break;
					if(mp[i]!=0){
						int o=min(p,mp[i]);
						p-=o;
						cnt-=o*i;
					}
				}
			}
			if(cnt1>n2){
				int p=cnt1-n2;
				for(int i=1;i<=n;i++){
					if(a1[i][2]==3){
						mp[a1[i][1]]++;
					}
				}
				for(int i=0;i<=200005;i++){
					if(!p)break;
					if(mp[i]!=0){
						int o=min(p,mp[i]);
						p-=o;
						cnt-=o*i;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}