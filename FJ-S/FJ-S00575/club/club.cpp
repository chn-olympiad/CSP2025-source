#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef pair<long long,long long> p;
int n,lim,t,a[N],b[N],c[N],ta,tb,tc,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
		ta=0,tb=0,tc=0,ans=0,lim=n>>1;
		priority_queue<p,vector<p>,greater<p> > aq,bq,cq;
		for(int i=1;i<=n;i++){
			int maxx=max(a[i],max(b[i],c[i]));
			if(maxx==a[i]){
				if(ta<lim){
					ta++;
					aq.push({a[i],i});
					ans+=a[i];
				}
				else{
					bool psh=1;
					p tmp=aq.top();
					int j=tmp.second;
					aq.pop();
					ans-=tmp.first;
					if(a[i]>tmp.first){
						ans+=a[i];
						aq.push({a[i],i});
						psh=0;
					}
					if(max(b[j],c[j])==b[j] and a[j]-b[j]<=a[i] and tb<lim){
						tb++;
						ans+=b[j];
						bq.push({a[j],j});
						ans+=a[i]*psh;
						if(!psh)aq.push({a[i],i});
					}
					else if(max(b[j],c[j])==c[j] and a[j]-c[j]<=a[i] and tc<lim){
						tc++;
						ans+=c[j];
						cq.push({a[j],j});
						ans+=a[i]*psh;
						if(!psh)aq.push({a[i],i});
					}
					else{
						maxx=max(b[i],c[i]);
					}		
				}
			}
			if(maxx==b[i]){
				if(tb<lim){
					tb++;
					bq.push({b[i],i});
					ans+=b[i];
				}
				else{
					bool psh=1;
					p tmp=bq.top();
					int j=tmp.second;
					bq.pop();
					ans-=tmp.first;
					if(b[i]>tmp.first){
						ans+=b[i];
						bq.push({b[i],i});
						psh=0;
					}
					if(max(a[j],c[j])==a[j] and b[j]-a[j]<=b[i] and ta<lim){
						ta++;
						ans+=a[j];
						aq.push({b[j],j});
						ans+=b[i]*psh;
						if(!psh)bq.push({b[i],i});
					}
					else if(max(a[j],c[j])==c[j] and b[j]-c[j]<=b[i] and tc<lim){
						tc++;
						ans+=c[j];						
						cq.push({b[j],j});
						ans+=b[i]*psh;
						if(!psh)bq.push({b[i],i});
					}
					else{
						maxx=max(a[i],c[i]);
					}
				}
			}
			if(maxx==c[i]){
				if(tc<lim){
					tc++;
					cq.push({c[i],i});
					ans+=c[i];
				}
				else{
					bool psh=1;
					p tmp=cq.top();
					int j=tmp.second;
					cq.pop();
					ans-=tmp.first;
					if(c[i]>tmp.first){
						ans+=c[i];
						cq.push({c[i],i});
						psh=0;
					}
					if(max(a[j],b[j])==a[j] and c[j]-a[j]<=c[i] and ta<lim){
						ta++;
						ans+=a[j];
						aq.push({c[j],j});
						ans+=c[i]*psh;
						if(!psh)cq.push({c[i],i});
					}
					else if(max(a[j],b[j])==b[j] and c[j]-b[j]<=c[i] and tb<lim){
						tb++;
						ans+=b[j];						
						bq.push({c[j],j});
						ans+=c[i]*psh;
						if(!psh)cq.push({b[i],i});
					}
					else{
						c[i]=0;
					}
				}
			}
		}
		cout<<ans<<endl; 
	}
	return 0;
}

