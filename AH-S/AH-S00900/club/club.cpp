#include<bits/stdc++.h>
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define mp make_pair
using namespace std;
bool cmp(pii nums1,pii nums2){
	return nums1.first>nums2.first;
}
int t,n,a,b,c,ca[100005],cb[100005],cc[100005];
vpii caa,cbb,ccc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		caa.clear();
		cbb.clear();
		ccc.clear();
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			if(a>b&&a>c) caa.push_back(mp(a,i));
			if(b>a&&b>c) cbb.push_back(mp(b,i));
			if(c>b&&c>a) ccc.push_back(mp(c,i));
			ca[i]=a,cb[i]=b,cc[i]=c;
		}
		int asi=caa.size(),bsi=cbb.size(),csi=ccc.size();
		while(asi>n/2||bsi>n/2||csi>n/2){
			if(asi>n/2){
				sort(caa.begin(),caa.end(),cmp);
				for(int i=n/2;i<(int)caa.size();i++){
					if(caa[i].second==-1) continue;
					if(cb[caa[i].second]>cc[caa[i].second]){
						cbb.push_back(caa[i]);
					} else{
						ccc.push_back(caa[i]);
					}
					caa[i].second=-1;
					asi--;
				}
			}
			if(bsi>n/2){
				sort(cbb.begin(),cbb.end(),cmp);
				for(int i=n/2;i<(int)cbb.size();i++){
					if(cbb[i].second==-1) continue;
					if(ca[cbb[i].second]>cc[cbb[i].second]){
						caa.push_back(cbb[i]);
					} else{
						ccc.push_back(cbb[i]);
					}
					cbb[i].second=-1;
					bsi--;
				}
			}
			if(csi>n/2){
				sort(ccc.begin(),ccc.end(),cmp);
				for(int i=n/2;i<(int)ccc.size();i++){
					if(ccc[i].second==-1) continue;
					if(ca[ccc[i].second]>cb[ccc[i].second]){
						caa.push_back(ccc[i]);
					} else{
						ccc.push_back(ccc[i]);
					}
					ccc[i].second=-1;
					csi--;
				}
			}
		}
		int ans=0;
		for(int i=0 ;i<caa.size();i++) if(caa[i].second!=-1) ans+=caa[i].first;
		for(int i=0 ;i<cbb.size();i++) if(cbb[i].second!=-1) ans+=cbb[i].first;
		for(int i=0 ;i<ccc.size();i++) if(ccc[i].second!=-1) ans+=ccc[i].first;
		cout<<ans<<endl;
	}
}
