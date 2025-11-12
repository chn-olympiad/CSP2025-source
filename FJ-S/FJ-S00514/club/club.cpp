#include<bits/stdc++.h>
using namespace std;
struct club{
	int t1;
	int t2;
	int t3;
}t[1000002];
bool cmp(club x,club y){
	return x.t1>y.t1;
}
bool cmpmax(club x,club y){
	return max(x.t1,max(x.t2,x.t3))>max(y.t1,max(y.t2,y.t3));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int abb;
	cin>>abb;
	while(abb--){
		int n,ansa=0,flag2=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>t[i].t1>>t[i].t2>>t[i].t3;
			if(t[i].t2!=0) flag2=1;
//			ansb+=max(t[i].t1,max(t[i].t2,t[i].t3));
		}
		if(flag2==0){
			sort(t+1,t+n+1,cmp);
			for(int i=1;i<=n/2;i++) ansa+=t[i].t1;
			cout<<ansa<<"\n";
		}
		else{
			int cnt1=0,cnt2=0,cnt3=0,ans=0;
			sort(t+1,t+n+1,cmpmax);
			for(int i=1;i<=n;i++){
				if(t[i].t1==max(t[i].t1,max(t[i].t2,t[i].t3))&&cnt1<=n/2-1){
					ans+=t[i].t1;
					cnt1++;
				}
				else if(t[i].t2==max(t[i].t2,t[i].t3)&&cnt2<=n/2-1){
					ans+=t[i].t2;
					cnt2++;
				}
				else if(cnt3<=n/2-1){
					ans+=t[i].t3;
					cnt3++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
//hnsrm?
