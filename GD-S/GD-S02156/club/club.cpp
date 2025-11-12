#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1e7+1000;
struct ren{
	ll zhi,biao;
}tuan1[maxn],tuan2[maxn],tuan3[maxn];
ll gui[maxn],ren1,ren2,ren3,ji,t,n,vis1[maxn],vis2[maxn],vis3[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ll ans=0,ren1=0,ren2=0,ren3=0,ji=0,t=0,n=0;
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>tuan1[i].zhi>>tuan2[i].zhi>>tuan3[i].zhi;
			if(tuan1[i].zhi>=tuan2[i].zhi && tuan1[i].zhi>=tuan3[i].zhi){
				ans+=tuan1[i].zhi;
				ren1++;
				gui[i]=1;
			}else if(tuan2[i].zhi>=tuan1[i].zhi && tuan2[i].zhi>=tuan3[i].zhi){
				ans+=tuan2[i].zhi;
				ren2++;
				gui[i]=2;
			}else{
				ans+=tuan3[i].zhi;
				ren3++;
				gui[i]=3;
			}
			tuan1[i].biao=i;
			tuan2[i].biao=i;
			tuan3[i].biao=i;
		}
		ll zui=n/2;
		if(ren1<=zui && ren2<=zui && ren3<=zui)cout<<ans<<endl;
		else{
			while(ren1>zui){
				ll cnt=INT_MIN;
				for(ll i=1;i<=ren1;i++){
					if(vis1[i])continue;
					ll temp=min(tuan3[i].zhi-tuan1[i].zhi,tuan2[i].zhi-tuan1[i].zhi);
					if(temp>cnt){
						ji=i;
						cnt=temp;
						
					}
				}
				ans+=cnt;
				if(tuan3[ji].zhi>tuan2[ji].zhi)ren3++;
				else ren2++;
				ren1--;
				vis1[ji]=1;		
			}
			while(ren2>zui){
				ll cnt=INT_MIN;
				for(ll i=1;i<=ren2;i++){
					if(vis2[i])continue;
					ll temp=min(tuan3[i].zhi-tuan2[i].zhi,tuan1[i].zhi-tuan2[i].zhi);
					if(temp>cnt){
						ji=i;
					}
					cnt=max(cnt,temp);
				}
				ans+=cnt;
				ren2--;
				vis2[ji]=1;	
				if(tuan3[ji].zhi>tuan1[ji].zhi)ren3++;
				else ren1++;	
			}
			while(ren3>zui){
				ll cnt=INT_MIN;
				for(ll i=1;i<=ren3;i++){
					if(vis3[i])continue;
					ll temp=min(tuan2[i].zhi-tuan3[i].zhi,tuan1[i].zhi-tuan3[i].zhi);
					if(temp>cnt){
						ji=i;
					}
					cnt=max(cnt,temp);
				}
				ans+=cnt;	
				ren3--;
				vis3[ji]=1;	
				if(tuan2[ji].zhi>tuan1[ji].zhi)ren2++;
				else ren1++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
