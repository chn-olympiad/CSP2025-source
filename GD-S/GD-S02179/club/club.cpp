#include<bits/stdc++.h>
using namespace std;
struct f{
	int A,B,C;
	int first,second,d;
}a[100005];//зЂвт
bool cmd(f x,f y){
	return x.d>y.d;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int TT;cin>>TT;
	while(TT--){
		int n;cin>>n;
		int cnta=0,cntb=0,cntc=0; 
		int ans=0;
		for(int i=1;i<=n;++i){
			a[i].A=0;
			a[i].B=0;
			a[i].C=0;
		}
		for(int i=1;i<=n;++i){
			cin>>a[i].A>>a[i].B>>a[i].C;
			if(a[i].A>=a[i].B&&a[i].A>=a[i].C){
				a[i].first=1;
				cnta++;
				if(a[i].B>=a[i].C){
					a[i].second=2;
					a[i].d=a[i].A-a[i].B;
				}
				if(a[i].C>a[i].B){
					a[i].second=3;
					a[i].d=a[i].A-a[i].C;
				}
			}
			if(a[i].B>=a[i].A&&a[i].B>=a[i].C){
				a[i].first=2;
				cntb++;
				if(a[i].A>=a[i].C){
					a[i].second=1;
					a[i].d=a[i].B-a[i].A;
				}
				else {
					a[i].second=3;
					a[i].d=a[i].B-a[i].C;
				}
			}
			if(a[i].C>=a[i].B&&a[i].C>=a[i].A){
				a[i].first=3;
				cntc++;
				if(a[i].A>=a[i].B){
					a[i].second=1;
					a[i].d=a[i].C-a[i].A;
				}
				else {
					a[i].second=2;
					a[i].d=a[i].C-a[i].B;
				}
			}
		}
		int n2=n/2;
		
		for(int i=1;i<=n;++i){
			if(a[i].first==1)ans+=a[i].A;
			if(a[i].first==2)ans+=a[i].B;
			if(a[i].first==3)ans+=a[i].C;
		}
		if(cnta<=n2&&cntb<=n2&&cntc<=n2){
			cout<<ans<<endl;
		}
		if(cnta>n2){
			sort(a+1,a+n+1,cmd);
			int cntt=0;
			for(int i=1;i<=n;++i){
				if(a[i].first==1){
					cntt++;
					if(cntt>n/2){
						ans-=a[i].d;
					}
				}
			}
			cout<<ans<<endl;
		}
		if(cntb>n2){
			sort(a+1,a+n+1,cmd);
			int cntt=0;
			for(int i=1;i<=n;++i){
				if(a[i].first==2){
					cntt++;
					if(cntt>n/2){
						ans-=a[i].d;
					}
				}
			}
			cout<<ans<<endl;
		}
		if(cntc>n2){
			sort(a+1,a+n+1,cmd);
			int cntt=0;
			for(int i=1;i<=n;++i){
				if(a[i].first==3){
					cntt++;
					if(cntt>n/2){
						ans-=a[i].d;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
