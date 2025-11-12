#include <bits/stdc++.h>
#define int long long
using namespace std;
int k[1010],d[100010],ve,t,m,n,ans,xa,xb,xc,ya,yb,yc,ta,tb,tc,a[100010][5],dp[100010][5],v[100010];
priority_queue<pair<int,int> > q1,q2,q3;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ve=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0) ve=1;
			q1.push({a[i][1],i});
			q2.push({a[i][2],i});
			q3.push({a[i][3],i});
		}
		if(n==2){
			ans=max(a[1][1]+a[2][2],a[1][1]+a[2][3]);
			ans=max(ans,max(a[1][2]+a[2][1],a[1][2]+a[2][3]));
			ans=max(ans,max(a[1][3]+a[2][1],a[1][3]+a[2][2]));
		}
		else if(!ve){
			for(int i=1;i<=n;i++) d[i]=a[i][1];
			sort(d+1,d+n+1);
			for(int i=n;i>n/2;i--) ans+=d[i];
		}
		else{
			m=n/2;
			for(int i=1;i<=n;i++){
				xa=xb=xc=ya=yb=yc=0;
				while(!q1.empty()&&v[q1.top().second]) q1.pop();
				if(!q1.empty()){
					xa=q1.top().first,ya=q1.top().second;
					q1.pop();
				}
				while(!q2.empty()&&v[q2.top().second]) q2.pop();
				if(!q2.empty()){
					xb=q2.top().first,yb=q2.top().second;
					q2.pop();
				}
				while(!q3.empty()&&v[q3.top().second]) q3.pop();
				if(!q3.empty()){
					xc=q3.top().first,yc=q3.top().second;
					q3.pop();
				}
				if(xa==xb&&xb==xc&&xc==ya&&ya==yb&&yb==yc&&yc==0) break;
				if(ya==yb&&yb==yc){
					v[ya]=1;
					int maxx=max(xa,max(xb,xc));
					if(maxx==xa&&ta<m) ta++,ans+=xa;
					else if(maxx==xa){
						maxx=max(xb,xc);
						if(maxx==xc&&tc<m) tc++,ans+=xc;
						else if(maxx==xb&&tb<m) tb++,ans+=xb;
					}
					if(maxx==xb&&tb<m) tb++,ans+=xb;
					else if(maxx==xb){
						maxx=max(xa,xc);
						if(maxx==xc&&tc<m) tc++,ans+=xc;
						else if(maxx==xa&&ta<m) ta++,ans+=xa;
					}
					if(maxx==xc&&tc<m) tc++,ans+=xc;
					else if(maxx==xc){
						maxx=max(xb,xa);
						if(maxx==xa&&ta<m) ta++,ans+=xa;
						else if(maxx==xb&&tb<m) tb++,ans+=xb;
					}
				}
				else if(ya==yb){
					if(xa>xb&&ta<m) ta++,ans+=xa;
					else if(xa>xb) tb++,ans+=xb;
					if(xa<xb&&tb<m) tb++,ans+=xb;
					else if(xa<xb) ta++,ans+=xa;
					v[ya]=1;
					if(tc<m) v[yc]=1,tc++,ans+=xc;
				}
				else if(ya==yc){
					if(xa>xc&&ta<m) ta++,ans+=xa;
					else if(xa>xc) tc++,ans+=xc;
					if(xa<xc&&tc<m) tc++,ans+=xc;
					else if(xa<xc) ta++,ans+=xa;
					v[ya]=1;
					if(tb<m) v[yb]=1,tb++,ans+=xb;
				}
				else if(yb==yc){
					if(xc>xb&&tc<m) tc++,ans+=xc;
					else if(xc>xb) tb++,ans+=xb;
					if(xc<xb&&tb<m) tb++,ans+=xb;
					else if(xc<xb) tc++,ans+=xc;
					v[yb]=1;
					if(ta<m) v[ya]=1,ta++,ans+=xa;
				}
				else{
					if(ta<m) v[ya]=1,ta++,ans+=xa;
					if(tb<m) v[yb]=1,tb++,ans+=xb;
					if(tc<m) v[yc]=1,tc++,ans+=xc;
				}
				//cout<<"m:"<<m<<" ta:"<<ta<<" tb:"<<tb<<" tc:"<<tc<<" ans:"<<ans<<'\n';
			}
		}
		cout<<ans<<'\n';
		ans=0;
		for(int i=1;i<=n;i++) v[i]=0;
		ta=tb=tc=0;
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		while(!q3.empty()) q3.pop();
	}
	return 0;
}
