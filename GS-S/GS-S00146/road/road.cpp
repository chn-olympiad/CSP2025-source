#include <bits/stdc++.h>
using namespace std;
int t=0,n=0,anum=0,bnum=0,cnum=0,at=0,bt=0,ct=0;
long long ans;
struct xh{
	int bm,fs;
};
struct human{
	int a,b,c,mx1,mx2,pt1,pt2,xh;
	bool emp;
}hu[100005];
struct yg{
	int xh,cz;
}ay[100005],by[100005],cy[100005];
human ap[100005],bp[100005],cp[100005];
bool cmp1(human x,human y){
	if(x.mx1>y.mx1){
		return true;
	}
	return false;
}
bool cmp2(human x,human y){
	if(x.mx2>y.mx2){
		return true;
	}
	return false;
}
bool cmp4(yg a,yg b){
	if(a.cz>b.cz){
		return true;
	}
	return false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		at=0;
		bt=0;
		ct=0;
		anum=0;
		bnum=0;
		cnum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			hu[i].xh=i;
			cin>>hu[i].a>>hu[i].b>>hu[i].c;
			if(hu[i].a>hu[i].b){//paixu
				if(hu[i].a>hu[i].c){
					hu[i].mx1=hu[i].a;
					hu[i].pt1=1;
					if(hu[i].b>hu[i].c){
						hu[i].mx2=hu[i].b;
						hu[i].pt2=2;
					}
					else{
						hu[i].mx2=hu[i].c;
						hu[i].pt2=3;
					}
				}
				else{
					hu[i].mx1=hu[i].c;
					hu[i].pt1=3;
					hu[i].mx2=hu[i].a;
					hu[i].pt2=1;
				}
			}
			else{
				if(hu[i].b>hu[i].c){
					hu[i].mx1=hu[i].b;
					hu[i].pt1=2;	
					if(hu[i].a>hu[i].c){
						hu[i].mx2=hu[i].a;
						hu[i].pt2=1;
					}
					else{
						hu[i].mx2=hu[i].c;
						hu[i].pt2=3;
					}
				}
				else{
					hu[i].mx1=hu[i].c;
					hu[i].pt1=3;
					hu[i].mx2=hu[i].a;
					hu[i].pt2=1;
				}	
			}
		}
		sort(hu+1,hu+1+n,cmp1);
		for(int i=1;i<=n;i++){
			if(hu[i].pt1==1){
				if(anum>=n/2){
					for(int j=1;j<=at;j++){
						if(hu[i].mx1-hu[i].mx2>ay[j].cz){
							hu[ay[j].xh].emp=false;
							ans-=hu[ay[j].xh].mx1;
							ans+=hu[i].mx1;	
						}
					}		
				}
				else{
					ans+=hu[i].mx1;
					anum++;
					hu[i].emp=true;
					at++;
					ay[at].xh=i;
					ay[at].cz=hu[i].mx1-hu[i].mx2;
					sort(ay+1,ay+1+at,cmp4);
				}
				
			}
			if(hu[i].pt1==2){
				if(bnum>=n/2){
					for(int j=1;j<=bt;j++){
						if(hu[i].mx1-hu[i].mx2>by[j].cz){
							hu[by[j].xh].emp=false;
							ans-=hu[by[j].xh].mx1;
							ans+=hu[i].mx1;
						}
					}
				}
				else{
					ans+=hu[i].mx1;
					bnum++;
					hu[i].emp=true;
					bt++;
					by[bt].xh=i;
					by[bt].cz=hu[i].mx1-hu[i].mx2;
					sort(by+1,by+1+bt,cmp4);
				}
			}
			if(hu[i].pt1==3){
				if(bnum>=n/2){
					for(int j=1;j<=ct;j++){
						if(hu[i].mx1-hu[i].mx2>cy[j].cz){
							hu[cy[j].xh].emp=false;
							ans-=hu[cy[j].xh].mx1;
							ans+=hu[i].mx1;	
						}
					}
				}
				else{
					ans+=hu[i].mx1;
					cnum++;
					hu[i].emp=true;
					ct++;
					cy[ct].xh=i;
					cy[ct].cz=hu[i].mx1-hu[i].mx2;
					sort(cy+1,cy+1+ct,cmp4);
				}
			}
		}
		sort(hu+1,hu+1+n,cmp2);
		for(int i=1;i<=n;i++){
			if(!hu[i].emp){
				ans+=hu[i].mx2;
				hu[i].emp=true;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
