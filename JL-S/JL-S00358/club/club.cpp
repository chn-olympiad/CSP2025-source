#include<bits/stdc++.h>
using namespace std;
long long t,n,c1[100001],c2[100001],c3[100001],maxn=-1,ans=0,p1=0,p2=0,p3=0,o1[100001],o2[100001],o3[100001],m1=INT_MAX,m2=INT_MAX,m3=INT_MAX;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>n;
		ans=0;
		for(int i=0;i<n;i++){
			cin>>c1[i]>>c2[i]>>c3[i];
			maxn=max(maxn,max(c1[i],max(c2[i],c3[i])));
			if(maxn==c1[i]) o1[p1]=i,p1++;
			if(maxn==c2[i]) o2[p2]=i,p2++;
			else o3[p3]=i,p3++;
			if(p1>(n/2)){
				for(int j=0;j<p1;j++){
					m1=min(m1,min(c1[o1[j]]-c2[o1[j]],c1[o1[j]]-c3[o1[j]]));
					if((c1[o1[j]]-c2[o1[j]])>(c1[o1[j]]-c3[o1[j]])){
						p3++;
						maxn=c3[o1[j]];
					}
					else{
						p2++;
						maxn=c2[o1[j]];
					}
				}
			}
			if(p2>(n/2)){
				for(int j=0;j<p2;j++){
					m2=min(m2,min(c2[o2[j]]-c1[o2[j]],c2[o2[j]]-c3[o2[j]]));
					if((c2[o2[j]]-c1[o2[j]])>(c2[o2[j]]-c3[o2[j]])){
						p3++;
						maxn=c3[o2[j]];
					}
					else{
						p1++;
						maxn=c1[o2[j]];
					}
				}
			}
			if(p3>(n/2)){
				for(int j=0;j<p3;j++){
					m3=min(m3,min(c3[o3[j]]-c2[o3[j]],c3[o3[j]]-c1[o3[j]]));
					if((c3[o3[j]]-c2[o3[j]])>(c3[o3[j]]-c1[o3[j]])){
						p1++;
						maxn=c1[o3[j]];
					}
					else{
						p2++;
						maxn=c2[o3[j]];
					}
				}
			}
			ans+=maxn;
			maxn=-1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
