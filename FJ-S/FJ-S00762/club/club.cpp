#include <bits/stdc++.h>
using namespace std;
int n,a[100500][4],hf,ad,id;
long long ans=0;
int pl[5]={0};
struct sm{
	int fl,sl,dis=0,lst=0,nm;
	bool vis=0;
}wk[100500];
bool cmp(sm x,sm y){
	return x.dis>y.dis;
}
bool cmpp(sm x,sm y){
	return x.lst>y.lst;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		hf=n/2,ad=1,id=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			ad=1,id=1;
			if(a[i][2]>a[i][1]){
				ad=2;
			}
			if(a[i][3]>a[i][ad]){
				ad=3;
			}
			if(a[i][2]<a[i][1]){
				id=2;
			}
			if(a[i][3]<a[i][id]){
				id=3;
			}
			for(int j=1;j<=3;j++){
				if(j!=ad && j!=id){
					wk[i].sl=j;
					break;
				} 
			}
			wk[i].dis=a[i][ad]-a[i][wk[i].sl];
			wk[i].fl=ad;
			wk[i].nm=i;
			wk[i].lst=a[i][wk[i].sl]-a[i][id];
		}
		sort(wk+1,wk+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(pl[wk[i].fl]+1<=hf){
				ans+=a[wk[i].nm][wk[i].fl];
				pl[wk[i].fl]++;
				wk[i].vis=1;
			}
		}
		sort(wk+1,wk+1+n,cmpp);
		for(int i=1;i<=n;i++){
			if(wk[i].vis==0){
				if(pl[wk[i].sl]+1<=hf){
					ans+=a[wk[i].nm][wk[i].sl];
					pl[wk[i].sl]++;
					wk[i].vis=1;
				}
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=0;
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			wk[i].dis=0,wk[i].lst=0,wk[i].nm=0;
			wk[i].fl=0,wk[i].sl=0,wk[i].vis=0;
		}
		for(int i=1;i<=3;i++){
			pl[i]=0;
		}
	}
	return 0;
} 
