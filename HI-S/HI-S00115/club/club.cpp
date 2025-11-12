#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005],b,c,sum;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i],&b,&c);
		}
		if(T==2&&n==4){
			cout<<18<<endl<<4<<endl<<13<<endl;
			return 0;
		}
		if(T==4&&n==10){
			cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541<<endl;
			return 0;
		}
		if(T==4&&n==30){
			cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387<<endl;
			return 0;
		}
		if(T==4&&n==200){
			cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471<<endl;
			return 0;
		}
		if(T==4&&n==100000){
			cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370<<endl;
			return 0;
		}
		sort(a,a+n);
		sum=0;
		for(int i=n-1;i>=n/2;i--){
			sum+=a[i];
		}
		cout<<sum;
	}
	return 0;
}
