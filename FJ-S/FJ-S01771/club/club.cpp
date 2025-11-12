#include<bits/stdc++.h>
using namespace std;
int t,n;
int wcd[100005]={0};
int na,nb,nc;
int sum[10]={0};
int ha,hb,hc;
struct nobea{
	int id;
	int xx;
}namea[100005];
struct nobeb{
	int id;
	int xx;
}nameb[100005];
struct nobec{
	int id;
	int xx;
}namec[100005];
bool ya(nobea x,nobea y){
	if(x.xx>=y.xx) return true;
//	else return false;
}
bool yb(nobeb x,nobeb y){
	if(x.xx>=y.xx) return true;
//	else return false;
}
bool yc(nobec x,nobec y){
	if(x.xx>=y.xx) return true;
//	else return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		na=0;
		nb=0;
		nc=0;
		cin>>n;
		wcd[100005]={0};
		for(int j=1;j<=n;j++){
			cin>>ha>>hb>>hc;
			namea[j].xx=ha;
			nameb[j].xx=hb;
			namec[j].xx=hc;
			
			namea[j].id=j;
			nameb[j].id=j;
			namec[j].id=j;
		}
		sort(namea+1,namea+n+1,ya);
		sort(nameb+1,nameb+n+1,yb);
		sort(namec+1,namec+n+1,yc);
		for(int j=1;j<=n;j++){
			if(na<=n/2&&wcd[namea[j].id]==0){
				wcd[namea[j].id]=1;
				na++;
				sum[i]+=namea[j].xx;
//				continue;
			}
			
			if(nb<=n/2&&wcd[nameb[j].id]==0){
				wcd[nameb[j].id]=1;
				nb++;
				sum[i]+=nameb[j].xx;
//				continue;
			}
			if(nc<=n/2&&wcd[namec[j].id]==0){
				wcd[namec[j].id]=1;
				nc++;
				sum[i]+=namec[j].xx;
//				continue;
			}
			
		}
		
		
//		cout<<endl;
//		for(int k=1;k<=n;k++){
//			
//				cout<<namea[k].id;
//			}
//		cout<<endl;
//		
		
	}
//	cout<<endl<<endl;
	
	for(int i=1;i<=t;i++){
		cout<<sum[i];
		cout<<endl;
	}
	
	return 0;
}
