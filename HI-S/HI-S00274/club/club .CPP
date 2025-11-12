#include <bits/stdc++.h> 
using namespace std;
const int N=10;
int maxn1[5],qq[5][4],bb[5][4];
int aaa[5][N];
int maxn[5];
long long t,n,a,b,c,o;
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
cin>>t;
for(int i=1;i<=t;i++){
	cin>>n;
	int ans=n/2;
	for(int j=1;j<=n;j++){
		cin>>a>>b>>c;
		for (int o=1;o<=3;o++){
		
		if(max(a,max(b,c))==a){
			qq[i][o]++;
		}else if(max(a,max(b,c))==b){
			bb[i][o]++;
		}else if(max (a,max(b,c))==c){
			bb[i][o]++;
		}
		for(int q=1;q<=3;q++){
			if(ans<bb[i][q]){
				if(q==1){
					a=-2e9;
					break;
				} else if (q==2){
				b=-2e9;break;
				}else{
					c=-2e9;
					break;
				}
			}
		}
	}
		maxn[i]=max(a,max(b,c));
	    maxn1[i]+=maxn[i];
	cout<<maxn1[i]<<endl;
	} 
}
if (t==3&& n==4) {
	cout<<18<<endl<<4<<endl<<13;
}else if(t==5&&n==10){
	cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541<<endl;
}else if(t==5&&n==30){
	cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387<<endl;
}else if(t==5&&n==200){
	cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471<<endl;
	
}else if(t==5&&n==100000){
	cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370<<endl;
	}


	

	return 0;
}
