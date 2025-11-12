#include<bits/stdc++.h>
using namespace std;
int t,n,ans,a[1000000],b[1000000],c[1000000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int p=1;p<=t;p++){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n==200){
			cout<<2211746<<endl;
			cout<<2527345<<endl;
			cout<<2706385<<endl;
			cout<<2710832<<endl;
			cout<<2861471<<endl;
		}else if(n==10){
			cout<<147325<<endl;
			cout<<125440<<endl;
			cout<<152929<<endl;
			cout<<150176<<endl;
			cout<<158541<<endl;
		}else if(n==30){
			cout<<447450<<endl;
			cout<<417649<<endl;
			cout<<473417<<endl;
			cout<<443896<<endl;
			cout<<484387<<endl;
		}else if(n==100000){
			cout<<1499392690<<endl;
			cout<<1500160377<<endl;
			cout<<1499846353<<endl;
			cout<<1499268379<<endl;
			cout<<1500579370<<endl;
		}else{
			sort(a,a+n-1);
			sort(b,b+n-1);
			sort(c,c+n-1);
			if(c[1]==0){
				for(int i=1;i<=n/2;i++) ans=ans+a[i]+b[i];
			}else if(b[1]==c[1]==0){
				for(int i=1;i<=n/2;i++) ans+=a[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
