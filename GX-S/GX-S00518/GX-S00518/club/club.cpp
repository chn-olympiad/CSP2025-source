#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,maxx,wz;
ll z[200009][4],zd[200009],cq[200009];
ll js[4],zz[10],py[200009];//pianyi
ll a,b,ans;
ll c(int x,int y,int z){
	int zz[4]={0,x,y,z};
	sort(zz+1,zz+1+3);
	return zz[3]-zz[2];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(py,0x37,sizeof(py));
		memset(js,0,sizeof(js));
		maxx=0;
		wz=0;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>z[i][1]>>z[i][2]>>z[i][3];
		}
		for(int i=1;i<=n;i++){
			maxx=0;wz=0;
			for(int j=1;j<=3;j++){
				if(z[i][j]>maxx) maxx=z[i][j],wz=j;
			}
			ans+=maxx;
			js[wz]++;
			zd[i]=wz;//zuida
		}
		if(max(js[1],max(js[2],js[3]))<=n/2) cout<<ans<<endl;
		else{
			maxx=0;wz=0;
			for(int i=1;i<=3;i++)
				if(js[i]>maxx) maxx=js[i],wz=i;//chao e deweizhi
			for(int i=1;i<=n;i++){
				if(zd[i]==wz){
					py[i]=c(z[i][1],z[i][2],z[i][3]);
				}
				//else py=1e9;
			}
			sort(py+1,py+1+n);
			for(int i=1;i<=js[wz]-n/2;i++) ans-=py[i];
			cout<<ans<<endl;
		}
	}
	return 0;
	}
