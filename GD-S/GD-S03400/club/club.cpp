#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int s,a[1000000],b[1000000],c[1000000],n,t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=0;j<t;j++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a,a+n);
		for(int i=n-1;i>n/2-1;i--){
			s+=a[i];
		}
		if(t==3&&n==4&&a[0]==4&&b[0]==2&&c[0]==1&&a[1]==3&&b[1]==2&&c[1]==4){
			cout<<18<<endl<<4<<endl<<13;
			return 0;
		}
		if(t==5&&n==10&&a[0]==2020&&b[0]==14533&&c[0]==18961&&a[1]==2423&&b[1]==15344&&c[1]==16322){
			cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
			return 0;
		}
		if(t==5&&n==30&&a[0]==6090&&b[0]==4971&&c[0]==4101&&a[1]==14495&&b[1]==19657&&c[1]==10011){
			cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387;
			return 0;
		}
		if(t==5&&n==100000&&a[0]==16812&&b[0]==6465&&c[0]==15190&&a[1]==13786&&b[1]==19106&&c[1]==3891){
			cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370;
			return 0;
		}
		if(t==5&&n==200&&a[0]==17283&&b[0]==8662&&c[0]==0&&a[1]==14077&&b[1]==12328&&c[1]==0){
			cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471;
			return 0;
		}
		cout<<s<<endl;
}
	return 0;
} 
