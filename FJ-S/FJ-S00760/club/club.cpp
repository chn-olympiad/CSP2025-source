#include <bits/stdc++.h>
using namespace std;
int t,n,a[111111],aa[111111],aaa[111111],ans,dd=111000;
bool d[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++){
		cin>>n;
		ans=0;
		a[0]=0;
		aa[0]=0;
		aaa[0]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>aa[i]>>aaa[i];
			dd=110000+q;
			d[1]=0;
			d[2]=0;
			d[3]=0;
			if(a[i]>=aa[i]&&a[i]>=aaa[i]){
				if(a[0]>=n/2){
					d[1]=1;
				}
				else{
					ans+=a[i];
					a[0]++;
				}
			}
			else if(a[i]<aa[i]&&aa[i]>=aaa[i]){
				if(aa[0]>=n/2){
					d[2]=1;
				}
				else{
					ans+=aa[i];
					aa[0]++;
				}
			}
			else if(aaa[i]>=aa[i]&&a[i]<aaa[i]){
				if(aaa[0]>=n/2){
					d[3]=1;
				}
				else{
					ans+=aaa[i];
					aaa[0]++;
				}
			}
			if(d[1]==1){
				for(int j=1;j<=a[0];j++){
					if(a[j]+max(aa[i],aaa[i])<a[i]+max(aa[j],aaa[j])&&a[j]+max(aa[dd],aaa[dd])>=a[dd]+max(aa[j],aaa[j])){
						dd=j;
					}
				}
				ans=ans+a[i]-a[dd]+max(aa[dd],aaa[dd]);
				swap(aaa[i],aaa[dd]);
				swap(aa[i],aa[dd]);
				swap(a[i],a[dd]);
				if(aa[dd]>=aaa[dd]){
					d[2]++;
				}
				else{
					d[3]++;
				}
			}
			else if(d[2]==1){
				for(int j=1;j<=aa[0];j++){
					if(aa[j]+max(a[i],aaa[i])<aa[i]+max(a[j],aaa[j])&&aa[j]+max(a[dd],aaa[dd])>=aa[dd]+max(a[j],aaa[j])){
						dd=j;
					}
				}
				ans+=aa[i]-aa[dd]+max(a[dd],aaa[dd]);
				swap(aaa[i],aaa[dd]);
				swap(aa[i],aa[dd]);
				swap(a[i],a[dd]);
				if(a[dd]>=aaa[dd]){
					d[1]++;
				}
				else{
					d[3]++;
				}
			}
			else if(d[3]==1){
				for(int j=1;j<=aaa[0];j++){
					if(aaa[j]-max(aa[i],a[i])<aaa[i]+max(aa[j],a[j])&&aaa[j]+max(aa[dd],a[dd])>=aaa[dd]+max(aa[j],a[j])){
						dd=j;
					}
				}
				ans+=aaa[i]-aaa[dd]+max(aa[dd],a[dd]);
				swap(aaa[i],aaa[dd]);
				swap(aa[i],aa[dd]);
				swap(a[i],a[dd]);
				if(aa[dd]>=a[dd]){
					d[2]++;
				}
				else{
					d[1]++;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
