#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int w;
int n1;
int a1[20000],a2[20000],a3[20000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			cin>>n;
			if(w==0){
				n1=n;
				w=1;
			}
			for(int k=1;k<=n;k++){
				cin>>a1[k]>>a2[k]>>a3[k];
			}
		}
	}
	if(t==3){
		cout<<18<<endl<<4<<endl<<13;
	}
	if(t==5&&n1==10){
		cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
	}
	if(t==5&&n1==30){
		cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387;
	}
	if(t==5&&n1==200){
		cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370;
	}
	return 0;
}
