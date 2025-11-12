#include<bits/stdc++.h>
using namespace std;
const int N=5005,MOD=998244353;
int n,a[N],ans,mx,cnt,ides,ma;
bool fool=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1) fool=0;
	}
	if(fool==1){
		ma=1;
		for(int i=n;i>=1;i--)
			ma=(ma*2)%MOD;
		ma=(ma-1-n-((n*(n-1))/2)+MOD)%MOD;
		cout<<ma;
		return 0;
	}else{
		for(int i=1;i<=(1<<n)-1;i++){
		//	cout<<"i:"<<i<<endl;
			ans=0,mx=-1,cnt=0;
			ides=i;
			for(int j=21;j>=0;j--){
				//cout<<"j:"<<j<<endl;
				if(ides>=(1<<j)){
					ans+=a[j];
					mx=max(mx,a[j]);
					ides-=(1<<j);
					cnt++;
				//	cout<<"ides:"<<ides<<",ans:"<<ans<<",mx:"<<mx<<",cnt:"<<cnt<<endl;
				}
			}
			if(ans>mx*2&&cnt>=3) ma=(ma+1)%MOD;
		//	cout<<"ma:"<<ma<<endl;
		}
		cout<<ma;
	}
	return 0;
}