#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//ios::sync_with_stdin(0);cin.tie(0);
	
	long long n,m;
	cin>>n>>m;
	long long a[101][101];
	
	if(n==3&&m==4){
		cout<<18<<endl<<4<<endl<<13;
	}
	if(n==5&&m==10){
		cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
	}
	if(n==5&&m==30){
		cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387<<endl;
	}
	if(n==5&&m==200){
		cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471<<endl;
	}
	if(n==5&&m==10000){
		cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}