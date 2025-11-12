#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t,n,lei[N],ans;
struct stu{
	int x,y,z,mx,cd,mi,mxi,cdi,mii,id;
	bool operator< (const stu &nw) const {
		int xa=mx,xb=cd,xc=mi,na=nw.mx,nb=nw.cd,nc=nw.mi;
		return (xa-xb)*xa*nb*nc>(na-nb)*na*xb*xc;
//		if(xa!=na) return xa>na;
//		if(xb!=nb) return xb>nb;
//		return xc>nc;
	}
}a[N];
priority_queue<stu> q[5];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].mx=max(a[i].x,max(a[i].y,a[i].z));
			a[i].mi=min(a[i].x,min(a[i].y,a[i].z));
			a[i].cd=a[i].x+a[i].y+a[i].z-a[i].mx-a[i].mi;
			if(a[i].x==a[i].mx) a[i].mxi=1;
			if(a[i].y==a[i].mx) a[i].mxi=2;
			if(a[i].z==a[i].mx) a[i].mxi=3;
			if(a[i].x==a[i].cd) a[i].cdi=1;
			if(a[i].y==a[i].cd) a[i].cdi=2;
			if(a[i].z==a[i].cd) a[i].cdi=3;
			if(a[i].x==a[i].mi) a[i].mii=1;
			if(a[i].y==a[i].mi) a[i].mii=2;
			if(a[i].z==a[i].mi) a[i].mii=3;
			a[i].id=i;
		}
		if(n==2){
			if(a[1].mxi!=a[2].mxi){
				cout<<a[1].mx+a[2].mx<<"\n";
			}else{
				cout<<max(a[1].mx+a[2].cd,a[1].cd+a[2].mx)<<"\n"; 
			}
			continue ; 
		}
		for(int i=1;i<=n;i++){
			vector<int> myd;
			if(a[i].mx==a[i].x){
				if(q[1].size()<n/2){
					myd.push_back(a[i].mx);
				}else{
					stu f=q[1].top();
					if(lei[f.id]==1){
						if(a[i].x+f.cd>f.x+a[i].cd&&q[f.cdi].size()<n/2){
							myd.push_back(-1);
							myd.push_back(a[i].x+f.cd-f.x);
						}else if(a[i].x+f.mi>f.x+a[i].mi&&q[f.mii].size()<n/2){
							myd.push_back(-1);
							myd.push_back(-1);
							myd.push_back(a[i].x+f.mi-f.x);
						}
					}else if(lei[f.id]==2){
						if(a[i].x+f.mi>f.x+a[i].cd&&q[f.mii].size()<n/2){
							myd.push_back(-1);
							myd.push_back(-1);
							myd.push_back(-1);
							myd.push_back(a[i].x+f.mi-f.x);
						}
					}
				}
			}
			if(a[i].mx==a[i].y){
				for(int i=1;i<=4;i++) myd.push_back(-1);
				if(q[2].size()<n/2){
					myd.push_back(a[i].mx);
				}else{
					stu f=q[2].top();
//					cout<<i<<" "<<f.id<<"\n";
					if(lei[f.id]==1){
						if(a[i].y+f.cd>f.y+a[i].cd&&q[f.cdi].size()<n/2){
							myd.push_back(-1);
//							cout<<i<<" jjj\n";
//							cout<<a[i].y+f.cd-f.y<<"\n";
							myd.push_back(a[i].y+f.cd-f.y);
						}else if(a[i].y+f.mi>f.y+a[i].mi&&q[f.mii].size()<n/2){
							myd.push_back(-1);
							myd.push_back(-1);
							myd.push_back(a[i].y+f.mi-f.y);
						}
					}else if(lei[f.id]==2){
						if(a[i].y+f.mi>f.y+a[i].cd&&q[f.mii].size()<n/2){
							myd.push_back(-1);
							myd.push_back(-1);
							myd.push_back(-1);
							myd.push_back(a[i].y+f.mi-f.y);
						}
					}
				}
			}
			if(a[i].mx==a[i].z){
				for(int i=1;i<=8;i++) myd.push_back(-1);
				if(q[3].size()<n/2){
					myd.push_back(a[i].mx);
				}else{
					stu f=q[3].top();
					if(lei[f.id]==1){
						if(a[i].z+f.cd>f.z+a[i].cd&&q[f.cdi].size()<n/2){
							myd.push_back(-1);
							myd.push_back(a[i].z+f.cd-f.z);
						}else if(a[i].z+f.mi>f.z+a[i].mi&&q[f.mii].size()<n/2){
							myd.push_back(-1);
							myd.push_back(-1);
							myd.push_back(a[i].z+f.mi-f.z);
						}
					}else if(lei[f.id]==2){
						if(a[i].z+f.mi>f.z+a[i].cd&&q[f.mii].size()<n/2){
							myd.push_back(-1);
							myd.push_back(-1);
							myd.push_back(-1);
							myd.push_back(a[i].z+f.mi-f.z);
						}
					}
				}
			}
			int mxx=0,mxxi=0;
			for(int i=0;i<myd.size();i++){
//				cout<<myd[i]<<" ";
				if(myd[i]>mxx){
					mxx=myd[i];
					mxxi=i+1;
				}
			}
//			cout<<"here "<<i<<" "<<mxx<<" "<<mxxi<<"\n";
			if(mxxi/4+1==a[i].mxi) lei[i]=1;
			if(mxxi/4+1==a[i].cdi) lei[i]=2;
			if(mxxi/4+1==a[i].mii) lei[i]=3;
			if(mxxi%4==1){
				q[mxxi/4+1].push(a[i]);
			}else if(mxxi%4==2){
				stu f=q[mxxi/4+1].top();
				q[mxxi/4+1].pop();
				q[mxxi/4+1].push(a[i]);
				q[f.cdi].push(f);
			}else if(mxxi%4==3||mxxi%4==4){
				stu f=q[mxxi/4+1].top();
				q[mxxi/4+1].pop();
				q[mxxi/4+1].push(a[i]);
				q[f.mii].push(f);
			}
		}
		while(!q[1].empty()){
			stu f=q[1].top();
			q[1].pop();
//			cout<<f.id<<" ";
			ans+=f.x;
		}
//		cout<<"A\n";
		while(!q[2].empty()){
			stu f=q[2].top();
			q[2].pop();
//			cout<<f.id<<" ";
			ans+=f.y;
		}
//		cout<<"B\n";
		while(!q[3].empty()){
			stu f=q[3].top();
			q[3].pop();
//			cout<<f.id<<" ";
			ans+=f.z;
		}
//		cout<<"C\n";
		cout<<ans<<"\n";
	}
	return 0;
}
