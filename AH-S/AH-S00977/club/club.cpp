#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+20;
struct club{
	ll c1,c2,c3;
}cl[N];
int n;
bool f;
bool cmp(club x,club y){
	return max(max(x.c1,x.c2),x.c3)>max(max(y.c1,y.c2),y.c3);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>cl[i].c1>>cl[i].c2>>cl[i].c3;
			if(cl[i].c1!=0||cl[i].c2!=0) f=1;
		}
		sort(cl+1,cl+n+1,cmp);
		if(f==0){
			int ans=0;
			for(int i=1;i<=n/2;i++) ans+=cl[i].c2;
			cout<<ans;
			continue;
		}
		if(n==2){
			int ans=0,a1=cl[1].c1,b1=cl[1].c2,c1=cl[1].c3,a2=cl[2].c1,b2=cl[2].c2,c2=cl[2].c3;
			ans=max(max(max(a1+b2,a1+c2),max(b1+a2,b1+c2)),max(c1+a2,c1+b2));
			cout<<ans;
			continue;
		}
		int a=n/2,b=n/2,c=n/2,ans=0;
		for(int i=1;i<=n;i++){
			ll u1=cl[i].c1;ll u2=cl[i].c2;ll u3=cl[i].c3;
			ll maxc=max(u1,u2);maxc=max(maxc,u3);
			if(maxc==u1){
				if(a>0) a--,ans+=u1;
				else{
					if(u2>u3){
						if(b>0) b--,ans+=u2;
						else{
							c--;
							ans+=u3;
						}
					}
					else{
						if(c>0) c--,ans+=u3;
						else b--,ans+=u2;
					}
				}
			}
			if(maxc==u2){
				if(b>0) b--,ans+=u2;
				else{
					if(u1>u3){
						if(a>0) a--,ans+=u1;
						else c--,ans+=u3;
					}
					else{
						if(c>0) c--,ans+=u3;
						else a--,ans+=u1;
					}
				}
			}
			if(maxc==u3){
				if(c>0) c--,ans+=u3;
				else{
					if(u2>u1){
						if(b>0) b--,ans+=u2;
						else a--,ans+=u1;
					}
					else{
						if(a>0) a--,ans+=u1;
						else b--,ans+=u2;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
