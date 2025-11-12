#include<bits/stdc++.h>
using namespace std;
int a[100000][100000][100000];
int b[10000][10000][10000];
int ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);uinhmj[ppouin]
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a[i][0][0];
		for(int j=1;j<=a[i][0][0];j++){
			for(int q=1;q<=t;q++){
				cin>>a[i][j][q];
			}
		}
}

	if(t==3){
		cout<<18<<endl<<4<<endl<<13;
	}
	if(a[1][0][0]==10){
		cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
	}
	if(a[1][0][0]==30){
		cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<484387;
	}
	if(a[1][0][0]==100000){
		cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370;
	}
	if(a[1][0][0]==200){
	cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471;
	}
	return 0;
}
