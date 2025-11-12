#include <bits/stdc++.h>
#define int long long 
using namespace std;
int T,n,suma=0,sumb=0,sumc=0,mx=0,Mx=0,ans=0;
struct node{
	int a,b,c,da,db,dc,id;
}a[100005];
bool cmp(node A,node B){
	return A.a>B.a;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1

1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
bool A=1;
signed main(){
	freopen("club.in","r",stdin);	
	freopen("club.out","w",stdout);	
	cin>>T;
	while(T--){
		ans=0,sumb=0,sumc=0,suma=0;
		cin>>n;
		mx=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].da=a[i].a-max(a[i].b,a[i].c);
			a[i].db=a[i].b-max(a[i].a,a[i].c);
			a[i].dc=a[i].c-max(a[i].a,a[i].b);
			if(a[i].da>=a[i].db && a[i].da>=a[i].dc) suma++,a[i].id=1;
			if(a[i].db>=a[i].da && a[i].db>=a[i].dc) sumb++,a[i].id=2;
			if(a[i].dc>=a[i].db && a[i].dc>=a[i].da) sumc++,a[i].id=3;
			if(a[i].b!=0 || a[i].c!=0) A=0;
		}
		if(A==1){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=mx;i++) ans+=a[i].a;
			cout<<ans<<'\n';
			continue;  
		}
		for(int i=1;i<=n;i++){
			if(a[i].id==1) ans+=a[i].a;
			else if(a[i].id==2) ans+=a[i].b;
			else if(a[i].id==3) ans+=a[i].c;
		}
		if(suma<=mx && sumb<=mx && sumc<=mx){
				cout<<ans<<'\n';
				continue;
		}
		while(suma>mx || sumb>mx || sumc>mx){
			Mx=-1e9;
			while(suma>mx){
				for(int i=1;i<=n;i++) if(a[i].id==1) Mx=max(a[i].db,max(Mx,a[i].dc));
				for(int i=1;i<=n;i++){
					if(a[i].db==Mx){
						suma--;
						sumb++;
						ans+=Mx;
						break;
					}
					if(a[i].dc==Mx){
						suma--;
						sumc++;
						ans+=Mx;
						break;
					}
				}
			}
			if(suma<=mx && sumb<=mx && sumc<=mx){
				cout<<ans<<'\n';
				break;
			}
			Mx=-1e9;
			while(sumb>mx){
				for(int i=1;i<=n;i++) if(a[i].id==2) Mx=max(a[i].da,max(Mx,a[i].dc)); 
				for(int i=1;i<=n;i++){
					if(a[i].da==Mx){
						sumb--;
						suma++;
						ans+=Mx;
						break;
					}
					if(a[i].dc==Mx){
						sumb--;
						sumc++;
						ans+=Mx;
						break;
					}
				}
			}
			if(suma<=mx && sumb<=mx && sumc<=mx){
				cout<<ans<<'\n';
				break;
			}
			Mx=-1e9;
			while(sumc>mx){
				for(int i=1;i<=n;i++) if(a[i].id==3) Mx=max(a[i].da,max(Mx,a[i].db));
				for(int i=1;i<=n;i++){
					if(a[i].da==Mx){
						sumc--;
						suma++;
						ans+=Mx;
						break;
					}
					if(a[i].db==Mx){
						sumc--;
						sumb++;
						ans+=Mx;
						break;	
					}
				}
			}
			if(suma<=mx && sumb<=mx && sumc<=mx){
				cout<<ans<<'\n';
				break;
			}
		}
	}
	return 0;
}
