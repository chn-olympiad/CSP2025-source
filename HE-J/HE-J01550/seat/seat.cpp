#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=1000;
int a[N],plr,plc;
int cnt=n*m+1;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
	cin>>a[i];
}
int l=a[1];
bool r=false;
	sort(a+1,a+1+n*m);
	cnt=n*m+1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
		     cnt--;
			 //cout<<a[cnt]<<' '<<cnt<<' '<<i<<' '<<j<<endl;	
			 if(a[cnt]==l){
			 	plc=i,plr=j;
			 	r=true;
			 	break;
			 }	
			}
		}
		else{
			for(int j=n;j>=1;j--){
				cnt--;
			//cout<<a[cnt]<<' '<<cnt<<' '<<i<<' '<<j<<endl;
			    if(a[cnt]==l){
			 	plc=i,plr=j;
			 	r=true;
			 	break;
			 }
			}
		}
		r=r;
		if(r==true)break;
	}
//	int l=
	
	
	cout<<plc<<' '<<plr;
	return 0;
}
