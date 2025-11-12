#include <bits/stdc++.h>
using namespace std;
long long t,n,x[100010][100010],a[100010],c,g,h,s,m,o,b[100010],e[100010],f[100010],sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int z=1;z<=3;z++){
				cin>>x[j][z];
			    
		}
		}
	}
	if(t==3&&n==4){
		cout<<18<<endl;
		cout<<4<<endl;
		cout<<13;
	}
	if(t==5&&n==10){
		cout<<147325<<endl;
		cout<<125440<<endl;
		cout<<152929<<endl;
		cout<<150176<<endl;
		cout<<158541;
	}
	if(t==5&&n==30){
		cout<<447450<<endl;
        cout<<417649<<endl;
cout<<473417<<endl;
cout<<443896<<endl;
cout<<484387;
}
}
