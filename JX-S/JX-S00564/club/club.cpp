#include<bits/stdc++.h>
using namespace std;
int ad[10005],bd[10005],cd[10005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==2){
			for(int i=1;i<=2;i++){
				cin>>ad[i]>>bd[i]>>cd[i];	
			}
			int sum[10];
			sum[1]=ad[1]+bd[2];
			sum[2]=ad[1]+cd[2];
			sum[3]=ad[2]+bd[1];
			sum[4]=ad[2]+cd[1];
			sum[5]=bd[1]+cd[2];
			sum[6]=cd[1]+bd[2];
			int zd=-1;
			for(int i=1;i<=6;i++){
				if(sum[i]>=zd){
					zd=sum[i];
				}
			}
			cout<<zd;
			return 0;
		}
		for(int i=1;i<=n;i++){
			cin>>ad[i]>>bd[i]>>cd[i];	
		}
		
		sort(ad+1,ad+1+n,greater<int>());
		sort(bd+1,bd+1+n,greater<int>());
		sort(cd+1,cd+1+n,greater<int>());
		int sum=0,zd=-1;
		for(int i=1;i<=n/2;i++){
			sum+=ad[i];
			sum+=bd[i];
		}
		if(sum>=zd){
			zd=sum;
			sum=0;
		}
		for(int i=1;i<=n/2;i++){
			sum+=ad[i];
			sum+=cd[i];
		}
		if(sum>=zd){
			zd=sum;
			sum=0;
		}
		for(int i=1;i<=n/2;i++){
			sum+=bd[i];
			sum+=cd[i];
		}
		if(sum>=zd){
			zd=sum;
			sum=0;
		}
		cout<<zd<<endl;
	}
return 0;
}
