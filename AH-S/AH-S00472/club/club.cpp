#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
struct D{int x,y;}d[N];
bool cmp(D i,D j){
	return i.y<j.y;
}
ll t,n,i,la,lb,lc,s,p,x,y,z,f[N][4],ma;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		vector<ll> a,b,c;
		s=0;
		for(i=1;i<=n;i++){
			cin>>x>>y>>z;
			ma=max(x,max(y,z));
			if(ma==x){
				a.push_back(i);
				s+=x;
			}
			else if(ma==y){
				b.push_back(i);
				s+=y;
			}
			else{
				c.push_back(i);
				s+=z;
			}
			f[i][1]=x;f[i][2]=y;f[i][3]=z;
		}
		la=a.size();
		lb=b.size();
		lc=c.size();
		if(la>n/2){
			for(i=0;i<la;i++){
				p=a[i];
				d[i+1].x=p;
				d[i+1].y=min(f[p][1]-f[p][2],f[p][1]-f[p][3]);
			}
			sort(d+1,d+1+la,cmp);
			for(i=1;i<=la;i++){
				if(la-i+1<=n/2)break;
				s-=d[i].y;
			}
		}
		if(lb>n/2){
			for(i=0;i<lb;i++){
				p=b[i];
				d[i+1].x=p;
				d[i+1].y=min(f[p][2]-f[p][1],f[p][2]-f[p][3]);
			}
			sort(d+1,d+1+lb,cmp);
			for(i=1;i<=lb;i++){
				if(lb-i+1<=n/2)break;
				s-=d[i].y;
			}
		}
		if(lc>n/2){
			for(i=0;i<lc;i++){
				p=c[i];
				d[i+1].x=p;
				d[i+1].y=min(f[p][3]-f[p][1],f[p][3]-f[p][2]);
			}
			sort(d+1,d+1+lc,cmp);
			for(i=1;i<=lc;i++){
				if(lc-i+1<=n/2)break;
				s-=d[i].y;
			}
		}
		cout<<s<<"\n";
	}
}
