#include<bits/stdc++.h>
using namespace std;
long long ans,t,n,a[100015][5],maxd[100015],maxa[100015],mopu,mopunum;
vector<int> wand1;
vector<int> wand2;
vector<int> wand3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int asd=1;asd<=t;asd++){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>=maxa[i]){
					maxa[i]=a[i][j];
					maxd[i]=j;
				}
			}
			ans+=maxa[i];
			if(maxd[i]==1){
				wand1.push_back(2*maxa[i]+min(a[i][1],min(a[i][2],a[i][3]))-(a[i][1]+a[i][2]+a[i][3]));
			}
			if(maxd[i]==2){
				wand2.push_back(2*maxa[i]+min(a[i][1],min(a[i][2],a[i][3]))-(a[i][1]+a[i][2]+a[i][3]));
			}
			if(maxd[i]==3){
				wand3.push_back(2*maxa[i]+min(a[i][1],min(a[i][2],a[i][3]))-(a[i][1]+a[i][2]+a[i][3]));
			}
		}
	//	cout<<ans<<endl;
		sort(wand1.begin(),wand1.end());
		sort(wand2.begin(),wand2.end());
		sort(wand3.begin(),wand3.end());
	//	cout<<wand1[0]<<" "<<wand1[1]<<endl;
		if(wand1.size()>mopunum){
			mopunum=wand1.size();
			mopu=1;
		}
		if(wand2.size()>mopunum){
			mopunum=wand2.size();
			mopu=2;
		}
		if(wand3.size()>mopunum){
			mopunum=wand3.size();
			mopu=3;
		}
	//	cout<<mopu;
		int qwe1=wand1.size();
		int qwe2=wand2.size();
		int qwe3=wand3.size();
		qwe1-=n/2+1;
		qwe2-=n/2+1;
		qwe3-=n/2+1;
		if(mopu==1){
			for(int i=0;i<=qwe1;i++){
			//	cout<<1;
				ans-=wand1[i];
			}
		}
		
		if(mopu==2){
			for(int i=0;i<=qwe2;i++){
			//	cout<<2;
				ans-=wand2[i];
			}
		}
		if(mopu==3){
			for(int i=0;i<=qwe3;i++){
			//	cout<<3;
				ans-=wand3[i];
			}
		}
		
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=0;
			}
			maxa[i]=0;
			maxd[i]=0;
		}
		mopu=0;
		mopunum=0;
		n=0;
		ans=0;
		wand1.clear();
		wand2.clear();
		wand3.clear();
	} 
	return 0;
} 
