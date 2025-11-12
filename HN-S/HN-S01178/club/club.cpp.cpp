#include<bits/stdc++.h>
using namespace std;
int t,n[6],ans[10005],q1=0,q2=0,q3=0,qnu[10005],qsh[10005],qji[10005],qpeo[10005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int t1=t/2;
	for(int j=1;j<=t;j++){
		cin>>n[j];
		int shu=n[j],use=1,al;
		for(int h=1;h<=3*n[j];h+=3){
			cin>>qnu[h]>>qnu[h+1]>>qnu[h+2];
			qsh[h]=1;
			qsh[h+1]=2;
			qsh[h+2]=3;
			qpeo[h]=use;
			qpeo[h+1]=use;
			qpeo[h+2]=use;
			use++;
		}
		sort(qnu,qnu+use+1);
		for(int h=n[j]*3;h>=1;h--){
			if(qpeo[h]=-1||q1==t1||q1==t1||q3==t1)break;
			if(qsh[h]==1)q1++;
			if(qsh[h]==2)q2++;
			if(qsh[h]==3)q3++;
			ans[j]+=qnu[h];
			qpeo[h]=-1;
		}
	}
	for(int j=1;j<=t;j++){
		cout<<ans[j]<<endl;
	}
	return 0;
}
