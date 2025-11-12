#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n;
ll a[100010][4];
ll ans;
struct node{
	ll id,num;
};
vector<node>toa,tob;
bool cmp(node a,node b){
	return a.num>b.num;
}
ll tmpa,tmpb;
bool flag[100010]; 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(ll i=1;i<=n;i++)
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		ans=0;
		toa.clear();
		tob.clear();
		memset(flag,0,sizeof flag);
		for(ll i=1;i<=n;i++){
			ans+=a[i][3];
			toa.push_back({i,a[i][1]-a[i][3]});
			tob.push_back({i,a[i][2]-a[i][3]});
		}
		sort(toa.begin(),toa.end(),cmp);
		sort(tob.begin(),tob.end(),cmp);
		tmpa=0,tmpb=0;
		ll cnta=0,cntb=0;
		while(cnta<n/2||cntb<n/2){
			
			
			while(flag[toa[tmpa].id])tmpa++;
			while(flag[tob[tmpb].id])tmpb++;
			
			ll numa=toa[tmpa].num;
			ll numb=tob[tmpb].num;
			ll ida=toa[tmpa].id;
			ll idb=tob[tmpb].id;
			ll ansp=ans;
			
			if(numa==numb){
				if(cnta<cntb){
					ans+=numa;
					flag[ida]=1;
					tmpa++;
					cnta++;
				
				}else{
					ans+=numb;
					flag[idb]=1;
					tmpb++;
					cntb++;
				}
			}else if(numa>numb&&cnta<n/2){
				ans+=numa;
				flag[ida]=1;
				tmpa++;
				cnta++;
			}else if(numa<numb&&cntb<n/2){
				ans+=numb;
				flag[idb]=1;
				tmpb++;
				cntb++;
			}else {
				if(cnta<cntb){
					ans+=numa;
					flag[ida]=1;
					tmpa++;
					cnta++;
				}else{
					ans+=numb;
					flag[idb]=1;
					tmpb++;
					cntb++;
				}
			}
			if(cnta+cntb-1>=n/2&&ansp>=ans){
				ans=ansp;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
	
}
